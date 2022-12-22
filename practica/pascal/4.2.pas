USES
    crt;

VAR
    FirstIndex, SecondIndex, CounterFirstIndex, CounterSecondIndex : integer;
    UserText, CorrectText : string;

BEGIN
    while (true) do
    begin   
        //ввід тексту
        writeln('Введіть текст:');
        write('    ');
        
        readln(UserText);

        
            //значення '0' для визначння, якщо не буде дужок у тексті
        FirstIndex := 0; //індекс першої дужки
        SecondIndex := 0; //індекс другої дужки
        CounterFirstIndex := 0; //кількість перших дужок
        CounterSecondIndex := 0; //кількість других дужок

        //цикл пошуку дужок і їх індекс у строці тексту
        for i : integer := 1 to length(UserText) do
        begin
            if (UserText[i] = '(') then
            begin
                FirstIndex := i;
                CounterFirstIndex := CounterFirstIndex + 1;
            end;
            
            if (UserText[i] = ')') then
            begin
                SecondIndex := i;
                CounterSecondIndex := CounterSecondIndex + 1;
            end;
        end;

        if ( (FirstIndex = 0) and (SecondIndex = 0) ) then //якщо у тексті немає дужок
        begin
            writeln();
            writeln('      ', 'У тексті відсутні дужки');
        end
        else 
        begin
            if (FirstIndex = 0) then //якщо немає дужки "("
            begin
                writeln();
                writeln('      ', 'У тексті немає дужки: "("');
            end
            else
            begin
                if (SecondIndex = 0) then //якщо немає дужки ")"
                begin
                    writeln();
                    writeln('      ', 'У тексті немає дужки: ")"');
                end
                else
                begin
                    if (CounterFirstIndex <> 1) then //якщо є кілька дужок "(" 
                    begin
                        writeln();
                        writeln('      ', 'У тексті є декілька дужок: "("');
                    end
                    else
                    begin

                        if (CounterSecondIndex <> 1) then //якщо є кілька дужок ")"
                        begin
                            writeln();
                            writeln('      ', 'У тексті є декілька дужок: ")"');
                        end
                        else 
                        begin
                            if (FirstIndex > SecondIndex) then //якщо дужки стоять ") текст ("
                            begin
                                writeln();
                                writeln('      ', 'У тексті введено фраграгмент: "текст ) текст ( текст"');
                            end
                            else //вихід з циклу
                            begin
                                break;
                            end;
                        end;
                    end;
                end;  
            end;
        end;
        
        writeln();
        writeln();
    end;

    CorrectText := '';

    for i : integer := 1 to (FirstIndex - 1) do //копіювання першої частини
    begin
        CorrectText := CorrectText + UserText[i];
    end;

    for i : integer := SecondIndex + 1 to length(UserText) do //копіювання другої частини
    begin
        CorrectText := CorrectText + UserText[i];
    end;
    
    writeln();
    writeln();
    writeln('Текст без дужок:');
    writeln('   ', CorrectText);
    
    readkey();
END.