USES
    crt;

VAR
    x1, y1, x2, y2, d, y : real;
    
    
BEGIN
    writeln('Введіть координати точки M1:');
    write('    ', 'x1: ');
    readln(x1);
    write('    ', 'y1: ');
    readln(y1);
    writeln('Введіть координати точки M2:');
    write('    ', 'x2: ');
    readln(x2);
    write('    ', 'y2: ');
    readln(y2);

    //розрахунок відстані
    d := power( ( power( (x2 - x1), 2) + power( (y2 - y1), 2) ), 1.0 / 2);
    writeln('Відстань між точками рівна d: ', d);
    
    //розрахунок формули
    y := ( power( sin(x2 + x1), 2) + cos( abs(x2 - y2) ) ) / ( cos(d) + power( ( 4.75 + 3.2 * power(d, 2) ), 1.0 / 2) ); 
    writeln('Розрахунок формули рівний y: ', y);
    
    readkey();
END.