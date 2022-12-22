USES
    crt;

CONST
    ConstCounterCopyMyArray = 10 * 10 - 1;

VAR
    x, y, A : real;

FUNCTION FuncY(ArgX : real): real; //функція
begin
    FuncY := power(ArgX, 5) * power( cos(1.0 / ArgX), 2);
end;

BEGIN
    write('Ведіть x: ');
    readln(x);
    writeln();
    write('Ведіть y: ');
    readln(y);
    writeln();

    A := ( power(FuncY(x), 2) + power(FuncY(y), 2) ) / 2;

    writeln('Значення виразу A: ', A);
    
    readkey();
END.