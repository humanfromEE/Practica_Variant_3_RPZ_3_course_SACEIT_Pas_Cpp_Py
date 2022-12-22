USES
    crt;

VAR
    i, j, factorial : integer;
    y : real;

LABEL 
    IfLabel, FactorialLabel;

BEGIN
    //використання if (за допомогою goto)
    writeln('Використанн¤ if (за допомогою goto):');
    
    y := 0;
    i := 1;

    IfLabel: //розрахунок ряду
        factorial := 1;
        j := 1;

        FactorialLabel: //розрахунок факторіалу
            if (j <= i) then
            begin
                factorial := factorial * j;
                j := j + 1;

                goto FactorialLabel;
            end;

        if (i <= 10) then
        begin
            y := y + 1.0 / factorial;
            writeln('   ', 'i: ', i, ' => факторіал: ', factorial, ' => y: ', y);

            i := i + 1;

            goto IfLabel;
        end;
 

    //використання циклу while
    writeln();
    writeln('Використання циклу while while:');

    y := 0;
    i := 1;

    while (i <= 10) do //розрахунок ряду
    begin
        factorial := 1;
        j := 1;

        while (j <= i) do //розрахунок факторіалу
        begin
            factorial := factorial * j;
            j := j + 1;
        end;

        y := y + 1.0 / factorial;
        writeln('   ', 'i: ', i, ' => факторіал: ', factorial, ' => y: ', y);
        
        i := i + 1;
    end;

    //використання циклу repeat
    writeln();
    writeln('Використання циклу repeat:');

    y := 0;
    i := 1;

    repeat //розрахунок ряду
        factorial := 1;
        j := 1;

        repeat //розрахунок факторіалу
            factorial := factorial * j;
            j := j + 1;
        until (j > i);

        y := y + 1.0 / factorial;
        writeln('   ', 'i: ', i, ' => факторіал: ', factorial, ' => y: ', y);
        
        i := i + 1;
    until (i > 10);
    
    
    //використання циклу for
    writeln();
    writeln('Використання циклу for:');

    y := 0;
    
    for i := 1 to 10 do //розрахунок ряду
    begin
        factorial := 1;

        for j := 1 to i do //розрахунок факторіалу
        begin
            factorial := factorial * j;
        end;

        y := y + 1.0 / factorial;
        writeln('   ', 'i: ', i, ' => факторіал: ', factorial, ' => y: ', y);
    end;
    
    readkey();
END.