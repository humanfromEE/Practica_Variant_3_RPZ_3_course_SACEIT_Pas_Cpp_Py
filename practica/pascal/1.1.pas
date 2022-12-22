USES
    crt;

VAR
    x, y : real;
    
BEGIN
    write('Введіть x: ');
    readln(x);
    
    y := log2( abs( (power(x, 2) - 4) / (power(x, 2) - 1) ) );
    writeln('Розрахунок формули рівний y: ', y);
    
    readkey();
END.