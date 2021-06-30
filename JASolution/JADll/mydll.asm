;-------------------------------------------------------------------------
.386 
.MODEL FLAT, c

OPTION CASEMAP:NONE

.NOLIST
.NOCREF
;INCLUDE    \masm32\include\windows.inc 
.LIST

.data 
PI_double REAL8 3.1415926535897932384626433
d100 REAL8 100.0
d60 REAL8 60.0
halfCircle REAL8 180.0
rozwiazanie REAL8 0.0
.code 

DllEntry PROC hInstDLL:DWORD, reason:DWORD, reserved1:DWORD

    MOV EAX, 1;TRUE 
    RET

DllEntry ENDP

;****************************************************************************
;Procedura RadToDeg
.686
.xmm
RadToDegAsm PROC rad:REAL8
movsd xmm1, halfCircle      ;180.0 w xmm1
divsd xmm1, PI_double       ;180'PI w xmm1
mulsd xmm1, rad             ;rad * 180/PI
CVTTSD2SI eax,xmm1          ;przeniesienie ulamka do eax

CVTSI2SD xmm0, eax          ;konwersja na double
subsd xmm1, xmm0            ;odejmowanie dajace czesc calkowita
pshufd xmm0,xmm0,40h        ;przeniesienie czesci calkowitej z qworda

movsd xmm0, xmm1            ;przeniesienie czesci ulamkowej do xmm0
movhpd xmm1, d100           ;zaladownie d100 do gornej czesci xmm1
movlpd xmm1, d60            ;zaladowanie d60 do dolnej czesci xmm1
mulpd xmm1, xmm0            ;mnozenie osobno czesci czalkowitej i po przecinku

pshufd xmm0, xmm1, 0Eh      ;przeniesienie calkowitej czesci xmm1 do dolnej czesci xmm0
addsd xmm1, xmm0            ;dodanie calosci i ulamkow
movsd rozwiazanie, xmm1     ;zapisanie wyniku do zmiennej
fld rozwiazanie             ;zwracanie wartosci przez ST(0)
ret
RadToDegAsm ENDP
;****************************************************************************
;Procedura CheckSSE w asm
CheckSSEAsm PROC NEAR 
    push ebx        ;zapisanie rejestrów na stos
    push ecx
    push edx
    mov eax,1
    cpuid
    xor eax,eax     ;bity ktore wspieraja SSE to ECX=0,9,19,20; EDX=19,25,26
    bt ecx,0        ;sprawdzenie rejestru ECX
    setc al
    bt ecx,9
    setc bl
    and al,bl
    bt ecx,19
    setc bl
    and al,bl
    bt ecx,20
    setc bl
    and al,bl
    bt edx,19       ;Sprawdzenie rejestru EDX
    setc bl
    and al,bl
    bt edx,25
    setc bl
    and al,bl
    bt edx,26
    setc bl
    and al,bl
    pop edx         ;przywrócenie wartoœci pozosta³ych rejestrów
    pop ecx
    pop ebx
    RET				; powrot z procedury 
CheckSSEAsm ENDP	

END DllEntry 
;**************************************************************************** 
