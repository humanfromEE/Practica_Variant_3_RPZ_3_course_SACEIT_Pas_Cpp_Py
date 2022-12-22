USES
    crt;

VAR
    NameFileReport, NameFileNumber, NameFileMarshut, NameFileType, NameFileStancia, NameFilePrice, Command, Answer : string;
    LengthLineProgram : integer;
{
    //перевірка наявності файлів і цілісність даних - PROCEDURE ProcCheckFiles();

    //табуляція - FUNCTION FuncWriteTab(CountTab : integer) : string;
    //вивід лінії - PROCEDURE ProcWriteLine(CountTab, LengthLine : integer; SymbolLine : char);

    //перевірка на долучення даних, якщо номер авіарейсу відсутній у БД - FUNCTION FuncCheckCommandOne(CountTab : integer; Number : string) : boolean;
    //перевірка на видалення редагування на існування номеру авіарейсу для подальших дій - FUNCTION FuncCheckCommandTwoThree(CountTab : integer; Number : string) : boolean;
    //кількість записів у БД - FUNCTION FuncCheckVoidBaseData() : integer;
    //долучення записів у кінець файлів - PROCEDURE ProcAppendDataInEndFile(NameFile, AppendValue : string);
    //видалення записів за номером строки - PROCEDURE ProcDeleteDataInFile(NameFile, SaveLine : string);
    //редагування записів за номером строки - PROCEDURE ProcEditDataInFile(NameFile : string; SaveLine : integer; NewValue : string);
    //вивід даних за номером строки - PROCEDURE ProcOutputDataInFile(Message : string; CountTab : integer; NameFile : string; SaveLine : integer);

    //команда 1 (долучення даних у БД) - PROCEDURE ProcCommandOne(CountTab : integer);
    //команда 2 (редагування даних у БД) - PROCEDURE ProcCommandTwo(CountTab : integer);
    //команда 3 (видалення даних у БД) - PROCEDURE ProcCommandThree(CountTab : integer);
    //команда 4 (вивід даних БД) - PROCEDURE ProcCommandFour(CountTab : integer);
    //команда 5 (вивід даних БД за вказаним типом літака) - PROCEDURE ProcCommandFive(CountTab : integer);

    //перевірка введеної команди - FUNCTION FuncCheckInputCommand(CountTab : integer; Command : string) : boolean;
    //створення звіту - PROCEDURE ProcCreateReport();
}

//перевірка наявності файлів і цілісність даних
PROCEDURE ProcCheckFiles();
var
    CreateAllFiles : boolean;
    File1, File2, File3, File4, File5 : text;
    ArrayCountersLine : array [0..4] of integer;
    TempString : string;
begin 
    CreateAllFiles := false;
    
    //перевірка існування усіх файлів
    if ( fileexists(NameFileNumber) and fileexists(NameFileMarshut) and fileexists(NameFileType) and fileexists(NameFileStancia) and fileexists(NameFilePrice) ) then
    begin
        assign(File1, NameFileNumber);
        assign(File2, NameFileType);
        assign(File3, NameFileMarshut);
        assign(File4, NameFileStancia);
        assign(File5, NameFilePrice);
        
        reset(File1);
        reset(File2);
        reset(File3);
        reset(File4);
        reset(File5);
        
        //присвоєння значень масиву для підрахунку кількості строк
        for i : integer := 0 to 4 do
        begin
            ArrayCountersLine[i] := 0;
        end;
        
		while (not File1.eof()) do
        begin
            readln(File1, TempString);
            ArrayCountersLine[0] := ArrayCountersLine[0] + 1;
        end;
		
        while (not File2.eof()) do
        begin
            readln(File2, TempString);
            ArrayCountersLine[1] := ArrayCountersLine[1] + 1;
        end;

        while (not File3.eof()) do
        begin
            readln(File3, TempString);
            ArrayCountersLine[2] := ArrayCountersLine[2] + 1;
        end;

        while (not File4.eof()) do
        begin
            readln(File4, TempString);
            ArrayCountersLine[3] := ArrayCountersLine[3] + 1;
        end;

        while (not File5.eof()) do
        begin
            readln(File5, TempString);
            ArrayCountersLine[4] := ArrayCountersLine[4] + 1;
        end;
        
        for i : integer := 0 to 4 do
        begin
            if (ArrayCountersLine[0] <> ArrayCountersLine[i]) then
            begin
                CreateAllFiles := true;
                
                break;
            end;
        end;
        
        close(File1);
        close(File2);
        close(File3);
        close(File4);
        close(File5);
    end
    else
    begin
        CreateAllFiles := true;
    end;
    
    writeln('ПОВІДОМЛЕННЯ!');
    
    if (CreateAllFiles) then
    begin
        assign(File1, NameFileNumber);
        assign(File2, NameFileType);
        assign(File3, NameFileMarshut);
        assign(File4, NameFileStancia);
        assign(File5, NameFilePrice);
        
        rewrite(File1);
        rewrite(File2);
        rewrite(File3);
        rewrite(File4);
        rewrite(File5);
        
        close(File1);
        close(File2);
        close(File3);
        close(File4);
        close(File5);
        
        writeln('    ', 'Файли БД не були знайдені (чи була нецілісність даних) і створююється нова БД');
    end
    else
    begin
        writeln('    ', 'БД була перевірена і відкрита!');
    end;
end;

//табуляція
FUNCTION FuncWriteTab(CountTab : integer) : string;
var
    ReturnString : string;
begin
    ReturnString := '';

    for i : integer := 1 to CountTab do
    begin
        ReturnString := ReturnString + '    ';
    end;

    FuncWriteTab := ReturnString;
end;

//вивід лінії
PROCEDURE ProcWriteLine(CountTab, LengthLine : integer; SymbolLine : char);
begin
    writeln();
    write(FuncWriteTab(CountTab));

    for i : integer := CountTab * 4 + 1 to LengthLine do
    begin
        write(SymbolLine);
    end;

    writeln();
    writeln();
end;

//перевірка на долучення даних, якщо номер авіарейсу відсутній у БД
FUNCTION FuncCheckCommandOne(CountTab : integer; Number : string) : boolean;
    var
        FileNumber : text;
        TempString : string;
        BoolTrueExit : boolean; //для виходу з результом false
begin
    assign(FileNumber, NameFileNumber);
    reset(FileNumber);
    
    BoolTrueExit := true;

    while (not FileNumber.eof()) do
    begin
        readln(FileNumber, TempString);

        if (TempString = Number) then
        begin
            close(FileNumber);

            ProcWriteLine(CountTab, LengthLineProgram, '!');
            writeln(FuncWriteTab(CountTab), 'Цей номер авіарейсу існує у БД, долучення даних неможливе, операцію скасовано!');
            ProcWriteLine(CountTab, LengthLineProgram, '!');

            FuncCheckCommandOne := false; //результат функції
            
            BoolTrueExit := false;
            
            break;
        end;
    end;

    if (BoolTrueExit) then
    begin
        close(FileNumber);
        
        FuncCheckCommandOne := true;
    end;
end;
    
//перевірка на видалення редагування на існування номеру авіарейсу для подальших дій
FUNCTION FuncCheckCommandTwoThree(CountTab : integer; Number : string) : boolean;
var
    FileNumber : text;
    TempString : string;
    BoolFalseExit : boolean; //для виходу з результом true
begin
    assign(FileNumber, NameFileNumber);
    reset(FileNumber);
    
    BoolFalseExit := true;

    while (not FileNumber.eof()) do
    begin
        readln(FileNumber, TempString);

        if (TempString = Number) then
        begin
            close(FileNumber);

            FuncCheckCommandTwoThree := true; //результат функції
            
            BoolFalseExit := false;
            
            break;
        end;
    end;
    
    if (BoolFalseExit) then
    begin
        close(FileNumber);
        
        ProcWriteLine(CountTab, LengthLineProgram, '!');
        writeln(FuncWriteTab(CountTab), 'Цей номер авіарейсу не знайдено у БД, дії з даними неможливі, операцію скасовано!');
        ProcWriteLine(CountTab, LengthLineProgram, '!');
        
        FuncCheckCommandTwoThree := false; 
    end;
end;

//кількість записів у БД
FUNCTION FuncCheckVoidBaseData() : integer;
var
    FileNumber : text;
    TempString : string;
    CounterLines : integer;
begin
    CounterLines := 0;

    assign(FileNumber, NameFileNumber);
    reset(FileNumber);

    while (not FileNumber.eof()) do
    begin
        readln(FileNumber, TempString);
        
        CounterLines := CounterLines + 1;
    end;

    close(FileNumber);

    FuncCheckVoidBaseData := CounterLines;
end;

//долучення записів у кінець файлів
PROCEDURE ProcAppendDataInEndFile(NameFile, AppendValue : string);
var
    FileApp : text;
begin
    if (AppendValue <> '') then
    begin
        assign(FileApp, NameFile);
        append(FileApp);
        writeln(FileApp, AppendValue);
        close(FileApp);
    end;
end;

//видалення записів за номером строки
PROCEDURE ProcDeleteDataInFile(NameFile : string; SaveLine : integer);
var
    FileDel, TempFile : text;
    TempString : string;
    CounterLines : integer;
begin
    //створення тимачасового файлу для збереження даних
    assign(TempFile, 'tempdata.txt');
    rewrite(TempFile);
    close(TempFile);


    //запис даних у тимчасовий файл
    assign(FileDel, NameFile);
    reset(FileDel);

    CounterLines := 0;

    while (not FileDel.eof()) do
    begin
        CounterLines := CounterLines + 1;
        
        readln(FileDel, TempString);

        if (CounterLines <> SaveLine) then
        begin
            ProcAppendDataInEndFile('tempdata.txt', TempString);
        end;
    end;

    close(FileDel);

    //перезапис даних
    assign(FileDel, NameFile);
    rewrite(FileDel);
    close(FileDel);
    
    

    assign(TempFile, 'tempdata.txt');
    reset(TempFile);

    while (not TempFile.eof()) do
    begin
        readln(TempFile, TempString);
        ProcAppendDataInEndFile(NameFile, TempString);
    end;
    
    close(TempFile);

    erase(TempFile); //видалення тимчасового файлу
end;

//видалення записів за номером строки
PROCEDURE ProcEditDataInFile(NameFile : string; SaveLine : integer; NewValue : string);
var
    FileEdit, TempFile : text;
    TempString : string;
    CounterLines : integer;
begin
    //створення тимачасового файлу для збереження даних
    assign(TempFile, 'tempdata.txt');
    rewrite(TempFile);
    close(TempFile);


    //запис даних у тимчасовий файл
    assign(FileEdit, NameFile);
    reset(FileEdit);

    CounterLines := 0;

    while (not FileEdit.eof()) do
    begin
        CounterLines := CounterLines + 1;
        
        readln(FileEdit, TempString);

        if (CounterLines <> SaveLine) then
        begin
            ProcAppendDataInEndFile('tempdata.txt', TempString);
        end
        else
        begin
            ProcAppendDataInEndFile('tempdata.txt', NewValue);
        end;
    end;

    close(FileEdit);

    //перезапис даних
    assign(FileEdit, NameFile);
    rewrite(FileEdit);
    close(FileEdit);

    assign(TempFile, 'tempdata.txt');
    reset(TempFile);

    while (not TempFile.eof()) do
    begin
        readln(TempFile, TempString);
        ProcAppendDataInEndFile(NameFile, TempString);
    end;
    
    close(TempFile);

    assign(TempFile, 'tempdata.txt');
    erase(TempFile); //видалення тимчасового файлу
end;

//вивід даних за номером строки
PROCEDURE ProcOutputDataInFile(Message : string; CountTab : integer; NameFile : string; SaveLine : integer);
var
    FileOut : text;
    TempString : string;
    CounterLines : integer;
begin
    CounterLines := 0; 

    assign(FileOut, NameFile);
    
    reset(FileOut);

    while (not FileOut.eof()) do
    begin
        CounterLines := CounterLines + 1;
        
        readln(FileOut, TempString);

        if ( (SaveLine = CounterLines) and (TempString <> '') ) then
        begin
            close(FileOut);

            writeln(FuncWriteTab(CountTab), Message, ': ', TempString);

            break;
        end;
    end;
end;

//команда 1 (долучення даних у БД)
PROCEDURE ProcCommandOne(CountTab : integer);
var
    Number, Marshut, NewType, Stancia, Price : string;
begin
    ProcWriteLine(CountTab, LengthLineProgram, '+');

    writeln(FuncWriteTab(CountTab), 'ДОЛУЧЕННЯ ЗАПИСУ');
    write(FuncWriteTab(CountTab + 1), 'введіть номер авіарейсу: ');
    readln(Number);

    if (FuncCheckCommandOne(CountTab + 2, Number)) then
    begin
        write(FuncWriteTab(CountTab + 1), 'введіть маршут: ');
        readln(Marshut);
        
        write(FuncWriteTab(CountTab + 1), 'введіть тип: ');
        readln(NewType);
        
        write(FuncWriteTab(CountTab + 1), 'введіть станцію: ');
        readln(Stancia);
        
        write(FuncWriteTab(CountTab + 1), 'введіть ціну квитка: ');
        readln(Price);

        //долучення даних у файл
        ProcAppendDataInEndFile(NameFileMarshut, Marshut);
        ProcAppendDataInEndFile(NameFileType, NewType);
        ProcAppendDataInEndFile(NameFileStancia, Stancia);
        ProcAppendDataInEndFile(NameFilePrice, Price);
        ProcAppendDataInEndFile(NameFileNumber, Number);
    end;

    ProcWriteLine(CountTab, LengthLineProgram, '+');
end;

//команда 2 (редагування даних у БД)
PROCEDURE ProcCommandTwo(CountTab : integer);
var
    FileNumber : text; 
    Number, Marshut, NewType, Stancia, Price, TempString : string;
    CounterLines : integer;
begin
    ProcWriteLine(CountTab, LengthLineProgram, '@');

    writeln(FuncWriteTab(CountTab), 'РЕДАГУВАННЯ ЗАПИСУ');
    write(FuncWriteTab(CountTab + 1), 'введіть номер авіарейсу (його не можна редагувати): ');
    readln(Number);

    if (FuncCheckCommandTwoThree(CountTab + 2, Number)) then
    begin
        //пошук строки редагування
        CounterLines := 0; 

        assign(FileNumber, NameFileNumber);
        reset(FileNumber);

        while (not FileNumber.eof()) do
        begin
            CounterLines := CounterLines + 1;
            
            readln(FileNumber, TempString);

            if (Number = TempString) then
            begin
                close(FileNumber);
                
                write(FuncWriteTab(CountTab + 1), 'введіть маршут: ');
                readln(Marshut);
                
                write(FuncWriteTab(CountTab + 1), 'введіть тип: ');
                readln(NewType);
                
                write(FuncWriteTab(CountTab + 1), 'введіть станцію: ');
                readln(Stancia);
                
                write(FuncWriteTab(CountTab + 1), 'введіть ціну квитка: ');
                readln(Price);

                //зміна даних
                ProcEditDataInFile(NameFileMarshut, CounterLines, Marshut);
                ProcEditDataInFile(NameFileType, CounterLines, NewType);
                ProcEditDataInFile(NameFileStancia, CounterLines, Stancia);
                ProcEditDataInFile(NameFilePrice, CounterLines, Price);

                break;
            end;
        end;
    end;

    ProcWriteLine(CountTab, LengthLineProgram, '@');
end;

//команда 3 (видалення даних у БД)
PROCEDURE ProcCommandThree(CountTab : integer);
var
    FileNumber : text; 
    TempString, Number : string;
    CounterLines : integer;
begin
    ProcWriteLine(CountTab, LengthLineProgram, '-');

    writeln(FuncWriteTab(CountTab), 'ВИДАЛЕННЯ ЗАПИСУ');
    write(FuncWriteTab(CountTab + 1), 'введіть номер авіарейсу: ');
    readln(Number);

    if (FuncCheckCommandTwoThree(CountTab + 2, Number)) then
    begin
        //пошук строки видалення
        CounterLines := 0; 

        assign(FileNumber, NameFileNumber);
        reset(FileNumber);

        while (not FileNumber.eof()) do
        begin
            CounterLines := CounterLines + 1;
            
            readln(FileNumber, TempString);

            if (Number = TempString) then
            begin
                close(FileNumber);
              
                ProcDeleteDataInFile(NameFileNumber, CounterLines);
                ProcDeleteDataInFile(NameFileMarshut, CounterLines);
                ProcDeleteDataInFile(NameFilePrice, CounterLines);
                ProcDeleteDataInFile(NameFileStancia, CounterLines);
                ProcDeleteDataInFile(NameFileType, CounterLines);
                
                break;
            end;
        end;
    end;

    ProcWriteLine(CountTab, LengthLineProgram, '-');
end;

//команда 4 (вивід даних БД)
PROCEDURE ProcCommandFour(CountTab : integer);
var
    CounterLines, CountLines : integer;
begin
    ProcWriteLine(CountTab, LengthLineProgram, '=');

    writeln(FuncWriteTab(CountTab), 'ВИВІД ЗАПИСІВ');

    //пошук вивід
    CounterLines := 0;
    CountLines := FuncCheckVoidBaseData();

    while (CounterLines < CountLines) do
    begin
        CounterLines := CounterLines + 1;
        
        ProcWriteLine(CountTab + 1, LengthLineProgram, '*');

        writeln(FuncWriteTab(CountTab + 1), 'запис №', CounterLines, ':');

        ProcOutputDataInFile('номер авіарейсу', CountTab + 2, NameFileNumber, CounterLines);
        ProcOutputDataInFile('маршут', CountTab + 2, NameFileMarshut, CounterLines);
        ProcOutputDataInFile('тип літака', CountTab + 2, NameFileType, CounterLines);
        ProcOutputDataInFile('ціна квитка', CountTab + 2, NameFilePrice, CounterLines);
        ProcOutputDataInFile('станція', CountTab + 2, NameFileStancia, CounterLines);

        ProcWriteLine(CountTab + 1, LengthLineProgram, '*');
    end;

    ProcWriteLine(CountTab, LengthLineProgram, '=');
end;

//команда 5 (вивід даних БД за вказаним типом літака)
PROCEDURE ProcCommandFive(CountTab : integer);
var
    FileType : text;
    InputType, TempString : string;
    CounterLines : integer;
    NotFind : boolean;
begin
    ProcWriteLine(CountTab, LengthLineProgram, '?');

    writeln(FuncWriteTab(CountTab), 'ПОШУК ЗАПИСІВ ЗА ТИПОМ ЛІТАКА');
    write(FuncWriteTab(CountTab + 1), 'введіть тип: ');
    readln(InputType);

    NotFind := true; //для виводу повідомлення, якщо не буде знайдено результатів

    //пошук строки
    CounterLines := 0; 
    
    assign(FileType, NameFileType);
    reset(FileType);

    while (not FileType.eof()) do
    begin
        CounterLines := CounterLines + 1;
        
        readln(FileType, TempString);

        if (InputType = TempString) then
        begin
            ProcWriteLine(CountTab + 2, LengthLineProgram, '*');

            writeln(FuncWriteTab(CountTab + 2), 'запис №', CounterLines, ':');

            ProcOutputDataInFile('номер авіарейсу', CountTab + 3, NameFileNumber, CounterLines);
            ProcOutputDataInFile('маршут', CountTab + 3, NameFileMarshut, CounterLines);
            ProcOutputDataInFile('тип літака', CountTab + 3, NameFileType, CounterLines);
            ProcOutputDataInFile('ціна квитка', CountTab + 3, NameFilePrice, CounterLines);
            ProcOutputDataInFile('станція', CountTab + 3, NameFileStancia, CounterLines);

            ProcWriteLine(CountTab + 2, LengthLineProgram, '*');

            NotFind := false;
        end;
    end;

    close(FileType);

    if (NotFind) then
    begin
        writeln(FuncWriteTab(CountTab + 2), 'дані для такого типу літака не знайдені');
    end;

    ProcWriteLine(CountTab, LengthLineProgram, '?');
end;

//перевірка введеної команди 
FUNCTION FuncCheckInputCommand(CountTab : integer; Command : string) : boolean;
var
    BoolFalseExit : boolean;
begin
    BoolFalseExit := true;
    
    for i : integer := 0 to 5 do
    begin
        if (Command = inttostr(i)) then
        begin
            FuncCheckInputCommand := true; //результат функції
            
            BoolFalseExit := false;
            
            break;
        end
    end;
    
    if (BoolFalseExit) then
    begin
        FuncCheckInputCommand := false;
        
        writeln(FuncWriteTab(CountTab), 'команда введена неправильно!');
    end;
end;

//створення звіту 
PROCEDURE ProcCreateReport();
var
    FileReport, File1, File2, File3, File4, File5 : text;
    Str1, Str2, Str3, Str4, Str5 : string;
    CounterLineFiles, CounterIteration : integer;
    
begin
    assign(FileReport, NameFileReport);
    rewrite(FileReport);

    CounterIteration := FuncCheckVoidBaseData();

    assign(File1, NameFileMarshut);
    assign(File2, NameFileNumber);
    assign(File3, NameFilePrice);
    assign(File4, NameFileStancia);
    assign(File5, NameFileType);
    reset(File1);
    reset(File2);
    reset(File3);
    reset(File4);
    reset(File5);

    CounterLineFiles := 0;

    while (CounterLineFiles < CounterIteration) do
    begin
        CounterLineFiles := CounterLineFiles + 1;
        
        readln(File1, Str1);
        readln(File2, Str2);
        readln(File3, Str3);
        readln(File4, Str4);
        readln(File5, Str5);

        writeln(FileReport, 'запис №', CounterLineFiles, ':');
        writeln(FileReport, '    маршут: ', Str1);
        writeln(FileReport, '    номер авіарейсу: ', Str2);
        writeln(FileReport, '    ціна квитка: ', Str3);
        writeln(FileReport, '    станція: ', Str4);
        writeln(FileReport, '    тип літака: ', Str5);
        writeln(FileReport, '');
    end;

    close(File1);
    close(File2);
    close(File3);
    close(File4);
    close(File5);

    close(FileReport);
end;

BEGIN
    //назви файлів
    NameFileReport :=  'звіт.txt';
    NameFileNumber :=  'номер авіарейсу.txt ';
    NameFileMarshut :=  'маршрут.txt ';
    NameFileType :=  'тип літака.txt ';
    NameFileStancia :=  'станція.txt ';
    NameFilePrice :=  'ціна квітка.txt ';
    
    //довжина тесту лінії
    LengthLineProgram := 125;
    
    ProcCheckFiles();

    ProcWriteLine(0, LengthLineProgram, '`');

    while (true)  do
    begin
        writeln('МЕНЮ:');
        writeln('    ', '1 - долучити запис');
        writeln('    ', '2 - редагувати запис');
        writeln('    ', '3 - видалити запис');
        writeln('    ', '4 - вивести записи');
        writeln('    ', '5 - вивести літаки за вказаним типом');
        writeln('    ', '0 - вихід з програми');
        writeln(FuncWriteTab(3), 'кількість записів у БД: ', FuncCheckVoidBaseData());
   
        write('        ', 'ваш вибір: ');
        readln(Command);

        if (FuncCheckInputCommand(3, Command)) then
        begin
            if (Command = '1') then
            begin
                ProcCommandOne(3);
            end
            else
            begin
                if ((Command = '2') and (FuncCheckVoidBaseData() > 0)) then
                begin
                    ProcCommandTwo(3);
                end
                else
                begin
                    if ((Command = '3') and (FuncCheckVoidBaseData() > 0))  then
                    begin
                        ProcCommandThree(3);
                    end
                    else
                    begin
                        if ((Command = '4') and (FuncCheckVoidBaseData() > 0)) then
                        begin
                            ProcCommandFour(3);
                        end
                        else
                        begin
                            if ((Command = '5') and (FuncCheckVoidBaseData() > 0)) then
                            begin
                                ProcCommandFive(3);
                            end
                            else
                            begin
                                if (Command <> '0') then //вивід повідомлення, що для виконання команди потрібен хоча б 1 запис
                                begin
                                    writeln(FuncWriteTab(3), 'для цієї комнади потрібен хочаб 1 запис у БД, долучіть запис');
                                end
                                else
                                begin
                                    writeln(FuncWriteTab(3), 'ВИХІД З ПРОГРАМИ');
                                    writeln(FuncWriteTab(4), 'Не видаляйте файли для повторного перезапуску');
                                    write(FuncWriteTab(4), 'Бажаєте створити звіт? ("+" - так): ');
                                    readln(Answer);
                                    
                                    if (Answer = '+') then
                                    begin
                                        ProcCreateReport();
                                        writeln(FuncWriteTab(5), 'Назва файлу: "', NameFileReport, '"');
                                    end;
                                    
                                    break;
                                end;
                            end;
                        end;
                    end;
                end;
            end;
        end;
            
        ProcWriteLine(0, LengthLineProgram, '`');
    end;

    ProcWriteLine(0, LengthLineProgram, '`');
    
    readkey();
END.