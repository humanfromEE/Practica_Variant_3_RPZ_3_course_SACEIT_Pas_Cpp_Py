USES
    crt;

VAR
    NumberMonth : integer;
    
BEGIN 
    write('Введіть номер місяця: ');
    readln(NumberMonth);
    
    //case
    writeln('Конструкція case:');
    write('    ');
    
    case (NumberMonth) of
        12, 1, 2:
            begin
                writeln('Зима');
            end;
        3, 4, 5:
            begin
                writeln('Весна');
            end;
        6, 7, 8:
            begin
                writeln('Літо');
            end;
        9, 10, 11:
            begin
                writeln('Осінь');
            end;
        else
        begin
            writeln('Задане число не є місяцем');
        end;
    end;
    
    //if
    writeln('Конструкція if:');
    write('    ');

    if ( (NumberMonth = 12) or (NumberMonth = 1) or (NumberMonth = 2) ) then
    begin
        writeln('Зима');
    end
    else
    begin   
        if ( (NumberMonth >= 3) and (NumberMonth <= 5) ) then
        begin
            writeln('Весна');
        end
        else
        begin
            if ( (NumberMonth >= 6)  and (NumberMonth <= 8) ) then
            begin
                writeln('Літо');
            end
            else
            begin
                if ( (NumberMonth >= 9) and (NumberMonth <= 1) )
                then
                begin
                    writeln('Весна');
                end
                else
                begin 
                    writeln('Задане число не є місяцем');
                end;
            end;
        end;
    end;
    
    readkey();
END.