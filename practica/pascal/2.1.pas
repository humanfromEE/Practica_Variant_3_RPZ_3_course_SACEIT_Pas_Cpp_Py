USES
    crt;

VAR
    x : integer;


BEGIN
    write('Введіть х: ');
    readln(x);
    
    if (x > 0) then
    begin
        x := x + 1;
    end
    else
    begin
        if (x < 0) then
        begin
            x := x - 2;
        end
        else
        begin
            x := 10;
        end;
    end;
    
    writeln('Після виконання умови для х: ', x);
    
    readkey();
END.