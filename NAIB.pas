program NAIB;
{$ASMMODE INTEL}
uses crt;
const N = 10;
var A: array[1..N] of longint;
i: 1..N;
Cnt, Max: longint;
begin
     Randomize;
     writeln('');
     write('MASSIVE:');
     for i := 1 to N do
     begin
          A[i] := random(10);
          Write(A[i]: 6);
     end;

     asm
        LEA ESI, A
        MOV EAX, [ESI]
        MOV EDX, 1
        MOV ECX, N
        DEC ECX
        ADD ESI, 4
    @1: CMP EAX, [ESI]
        JNE @2
        INC EDX
        JMP @3
    @2: JG @3
        MOV EAX, [ESI]
        MOV EDX, 1
    @3: ADD ESI, 4
        LOOP @1
        MOV Cnt, EDX
        MOV Max, EAX
     end;
     writeln('');
     Writeln('The maximum element of the array is ',Max,' and occurs ',Cnt,' times');
     writeln('');
end.