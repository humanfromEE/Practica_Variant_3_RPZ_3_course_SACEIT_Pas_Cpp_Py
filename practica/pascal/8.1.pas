USES
    crt;

TYPE
    DataStruct = record
        Marka : string; //марка автомобіля
        PIB : string; //піб власника
        Year : integer; //рік випуску
        Number : integer; //реєстраційний номер (5 символів)
    end;

VAR
    MyArray : array [0..99] of DataStruct;
    CounterMyArray : integer;
    M, P : string;
    Y, N : integer;
    Answer, SearchMarka : string;
    CounterSearchMarka, MinYear, MaxYear : integer;
    TempVar : DataStruct;

FUNCTION FuncCheckYear() : boolean; //функція перевірки року випуску
begin
    if ( (Y <= 2022) and (Y >= 1900) ) then
    begin
        FuncCheckYear := true;
    end
    else
    begin
        write('            ');
        writeln('Введіть рік в діапазоні [1900; 2022]');
        writeln();
        writeln();
        
        FuncCheckYear := false;
    end;
end;

FUNCTION FuncCheckNumber() : boolean; //функція перевірки реєстраційного номеру
var
    ReturnBool : boolean;
begin
    if ( not( (N <= 99999) and (N >= 10000) ) ) then //перевірка діапазону (5 цифр)
    begin
        write('            ');
        writeln('Реєстраційний номер введений неправильному діапазоні [10000; 99999]');
        writeln();
        writeln();
        
        FuncCheckNumber := false;
    end
    else
    begin

        ReturnBool := false;

        for i : integer := 0 to (CounterMyArray - 1) do //перевірка наявності такого номеру у масиві
        begin
            if (MyArray[i].Number = N) then
            begin
                write('            ');
                writeln('Реєстраційний номер належить іншому користувачу');
                writeln();
                writeln();
                
                ReturnBool := true;

                break;
            end;
        end;

        if (ReturnBool) then
        begin
            FuncCheckNumber := false;
        end
        else
        begin
            FuncCheckNumber := true;
        end;
    end;
end;

BEGIN
    CounterMyArray := 0;

    writeln('Ввід користувачів (мінімум 3 користувачі)');

    //цикл вводу користувачів
    while (true) do
    begin
        writeln('    ', 'Введіть дані користувача №', CounterMyArray + 1);
        write('        ', 'марка: ');
        readln(M);
        write('        ', 'піб: ');
        readln(P);
        write('        ', 'рік випуску: ');
        readln(Y);
        write('        ', 'реєстраційний номер: ');
        readln(N);

        //перевірка на правильність введення даних і долучення користвувача
        if ( FuncCheckYear() and FuncCheckNumber() ) then
        begin
            writeln('            ', 'Користувач долучений!');
            
            MyArray[CounterMyArray].Marka := M;
            MyArray[CounterMyArray].PIB := P;
            MyArray[CounterMyArray].Year := Y;
            MyArray[CounterMyArray].Number := N;

            CounterMyArray := CounterMyArray + 1;
        end;

        writeln();
        writeln('    ', '-----------');
        write('        ');
        write('Бажаєте долучити ще користувача? ("+" - так): ');
        readln(Answer);
        writeln('    ', '-----------');
        writeln();
        
        //вихід з циклу
        if ( (Answer <> '+') or (CounterMyArray = 100) ) then
        begin
            if (CounterMyArray >= 3) then
            begin
                break;
            end
            else
            begin
                write('        ');
                writeln('Вихід неможливий, у вас введено менше 3 користувачів');
                writeln();
                writeln();
            end;
        end;
    end;

    writeln();
    writeln();
    writeln('Вивід користувачів [рік - піб - марка - номер]:');
    
    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        write('    ', '[' , MyArray[i].Year , ', ');
        write('"', MyArray[i].PIB , '"', ', '); 
        write('"', MyArray[i].Marka , '"', ', '); 
        writeln(MyArray[i].Number , ']');
    end;

    //пункт 1
    writeln();
    writeln();
    write('Введіть марку для пошуку кількості автомобілів цієї марки: ');
    readln(SearchMarka);

    CounterSearchMarka := 0;

    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        if (MyArray[i].Marka = SearchMarka) then
        begin
            CounterSearchMarka := CounterSearchMarka + 1;
        end;
    end;

    writeln('    ', 'Кількість: ', CounterSearchMarka);
    writeln();

    //пункт 2
    writeln();
    writeln();
    writeln('Вивід цих автомобілів зазначеної марки впорядкованим за піб і з реєстраційним номером: ');

    for i : integer := 1 to (CounterMyArray - 1) do
    begin
        for j : integer := 0 to (CounterMyArray - 1 - i) do
        begin
            if (MyArray[j].PIB > MyArray[j + 1].PIB) then
            begin
                TempVar := MyArray[j];
                MyArray[j] := MyArray[j + 1];
                MyArray[j + 1] := TempVar;
            end;
        end;
    end;

    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        if (CounterSearchMarka > 0) then
        begin
            if (MyArray[i].Marka = SearchMarka) then
            begin
                writeln('    ', '[', '"', MyArray[i].PIB, '"', ', ' , MyArray[i].Number, ']');
            end;
        end
        else
        begin
            writeln('    ', 'користувачі зазначеної марки відсутні!');
            
            break;
        end;
    end;

    writeln();
    writeln();

    //пункт 3
    while (true) do //цикл вводу
    begin
        write('Вивід мінімального року: ');
        readln(MinYear);
        write('Вивід максимального року: ');
        readln(MaxYear);
        
        if ( FuncCheckYear() and FuncCheckYear() ) then
        begin
            if (MaxYear >= MinYear) then
            begin
                break;
            end
            else
            begin
                writeln('        ', 'Мінімальний рік більший за максимальний, перевведіть!');
                writeln();
                writeln();
            end;
        end;
    end;

    writeln();
    writeln('Вивід марок і реєстраційних номерів за вказаним діапазон років:');

    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        if ( (MyArray[i].Year <= MaxYear) and (MyArray[i].Year >= MinYear) ) then
        begin
            writeln('    ', '[', '"', MyArray[i].Marka, '"', ', ' , MyArray[i].Number, ']');
        end;
    end;
    
    readkey();
END.