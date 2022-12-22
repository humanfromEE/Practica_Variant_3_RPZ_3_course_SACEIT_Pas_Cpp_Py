USES
    crt;

VAR
    x, a, b, c, y : real;
    
BEGIN 
    write('Введіть х: ');
    readln(x);
  
    //розрахунок параметрів
    a := power( (3 * log(7)), 1.0 / 2);
    b := tan(pi / 3); 
    c := exp(-2);
    
    writeln();
    writeln('Значення параметрів:');
    writeln('    ', 'a = ', a);
    writeln('    ', 'b = ', b);
    writeln('    ', 'c = ', c);
    writeln();

    if (x > a) then //умова завдання
    begin
        y := arctan(power(2, x)) + a * log(b * c);
        writeln('Розрахунок формули х > a, y: ', y);
    end
    else
    begin

        if (x = a) then //умова завдання
        begin
            y := exp(x - b) + log( power( (a * c), 1.0 / 2));
            writeln('Розрахунок формули х = a, y: ', y);
        end
        else //умова завдання
        begin
            y := power( (power(a, 2) + power(b, 2)), 1.0 / 3) + exp(x - c) * log(x);
            writeln('Розрахунок формули х < a, y: ', y);
        end;

    end;
    
    readkey();
END.