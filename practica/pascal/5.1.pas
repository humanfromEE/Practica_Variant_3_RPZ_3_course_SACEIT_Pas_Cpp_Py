USES
    crt;

CONST
    CounterRows = 4 - 1;
    CounterColumn = 3 - 1;

VAR
    MyArray : array [0..CounterRows, 0..CounterColumn] of integer;
    TempVar : integer;

BEGIN
    //заповнення матриці
    writeln('Ввід матриці 4х3:');
    
    for i : integer := 0 to CounterRows do
    begin
        for j : integer := 0 to CounterColumn do
        begin
            MyArray[i, j] := random(10); 
            
            writeln('   ', 'елемент №', i + 1, j + 1, ': ', MyArray[i, j]);
        end;
    end;

    writeln();
    writeln(); 
    writeln();   

    //вивід матриці
    writeln('Вивід матриці 4х3:'); 
    
    for i : integer := 0 to CounterRows do
    begin
        write('    ');
        
        for j : integer := 0 to CounterColumn do
        begin
            write(MyArray[i, j], ' ');
        end;

        writeln();
    end;

    writeln();
    writeln();
    writeln();

    //сортування рядків
    for i : integer := 0 to CounterRows do //цикл рядків
    begin
        //сортування методом бульбашки
        for j : integer := 1 to CounterColumn do
        begin
            for k : integer := 0 to (CounterColumn - j) do
            begin
                if (MyArray[i, k] > MyArray[i, k + 1]) then
                begin
                    TempVar := MyArray[i, k];
                    MyArray[i, k] := MyArray[i, k + 1];
                    MyArray[i, k + 1] := TempVar;
                end;
            end;
        end;
    end;

    //вивід матриці
    writeln('Вивід сортованої матриці 4x3 за збільшення рядка: ');
    
    for i : integer := 0 to CounterRows do
    begin
        write('    ');
        
        for j : integer := 0 to CounterColumn do
        begin
            write(MyArray[i, j], ' ');
        end;

        writeln();
    end;

    readkey();
END.