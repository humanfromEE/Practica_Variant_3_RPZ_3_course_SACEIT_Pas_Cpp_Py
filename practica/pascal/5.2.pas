USES
    crt;

CONST
    ConstCounterCopyMyArray = 10 * 10 - 1;

VAR
    MyArray : array [0..9, 0..9] of integer;
    CopyMyArray : array [0..ConstCounterCopyMyArray] of integer;
    CounterMyArray : integer;

PROCEDURE ProcGenerateMyArray(); //генерування матриці
begin
    writeln('Заповнення масиву випадковими числами: ');
    write('    ');

    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        for j : integer := 0 to (CounterMyArray - 1) do
        begin
            MyArray[i, j] := random(9);

            writeln('елемент №', i + 1, '-', j + 1, ': ', MyArray[i, j]);
            write('    ');
        end;
    end;

    writeln();
    writeln(); 
    writeln();
end;

PROCEDURE ProcOutputMyArray(Message : string); //вивід матриці
begin
    writeln(Message, ': ');
    

    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        write('    ');

        for j : integer := 0 to (CounterMyArray - 1) do
        begin
            write(MyArray[i, j], ' ');
        end;

        writeln();
    end;

    writeln();
    writeln(); 
    writeln();
end;

PROCEDURE ProcCopyMyArray(); //копіювання масиву значеннями матриці
var
    CounterCopyMyArray : integer;
begin
    CounterCopyMyArray := 0;

    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        for j : integer := 0 to (CounterMyArray - 1) do
        begin
            CopyMyArray[CounterCopyMyArray] := MyArray[i, j];

            CounterCopyMyArray := CounterCopyMyArray + 1;
        end;
    end;
end;

PROCEDURE ProcOutputCopyMyArray(Message : string); //вивід копіювального масиву
begin
    writeln(Message, ': ');
    write('    ');
    
    for i : integer := 0 to (CounterMyArray * CounterMyArray - 1) do
    begin
        if ((i + 1) mod 25 = 0) then
        begin
            writeln(CopyMyArray[i]);
            write('    ');
        end
        else
        begin
            write(CopyMyArray[i], ' ');
        end;
    end;

    writeln();
    writeln(); 
    writeln();
end;

PROCEDURE ProcSortArray(); //сортування масиву копії методом вибору
var
    TempVar : integer;
begin
    for i : integer := 0 to (CounterMyArray * CounterMyArray - 1 - 1) do
    begin
        for j : integer := i + 1 to (CounterMyArray * CounterMyArray - 1) do
        begin
            if (CopyMyArray[i] > CopyMyArray[j]) then
            begin
                TempVar := CopyMyArray[i];
                CopyMyArray[i] := CopyMyArray[j];
                CopyMyArray[j] := TempVar;
            end;
        end;
    end;
end;

PROCEDURE ProcCreateTrueMatrix(); //процедура створення потрібної матриці зі завдання
var
    CounterCopyMyArray : integer;
begin
    CounterCopyMyArray := 0;

    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        if ((i + 1) mod 2 <> 0) then //непарний рядок буде за спаданням
        begin
            for j : integer := CounterMyArray - 1 downto 0 do
            begin
                MyArray[i, j] := CopyMyArray[CounterCopyMyArray];

                CounterCopyMyArray := CounterCopyMyArray + 1;
            end;
        end
        else //парний рядок буде за зростанням
        begin
            for j : integer := 0 to (CounterMyArray - 1) do
            begin
                MyArray[i, j] := CopyMyArray[CounterCopyMyArray];

                CounterCopyMyArray := CounterCopyMyArray + 1;
            end;
        end;
    end;
end;



//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



BEGIN
    //цикл вводу розмірності матриці
    while (true) do
    begin
        write('Введіть розмірність матриці: ');
        readln(CounterMyArray);
        
        if ( (CounterMyArray <= 10) and (CounterMyArray > 1) ) then
        begin
            break;
        end
        else
        begin  
            writeln('   ', 'Розмірність повинна бути в діпазоні [2; 10]');
            writeln();
            writeln(); 
            writeln(); 
        end;
    end;

    writeln();
    writeln(); 
    writeln();   

    ProcGenerateMyArray();
    ProcOutputMyArray('Вивід згенерованої матриці');
    ProcCopyMyArray();
    ProcOutputCopyMyArray('Вивід масиву значень матриці');
    ProcSortArray();
    ProcOutputCopyMyArray('Сортований вивід масиву значень матриці');
    ProcCreateTrueMatrix();
    ProcOutputMyArray('Вивід матриці завдання');
    
    readkey();
END.