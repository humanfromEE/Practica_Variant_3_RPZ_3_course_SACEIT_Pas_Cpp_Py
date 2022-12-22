USES
    crt;

VAR
    CounterMyArray : integer;
    SummMinus, SummPlus: real;
    MyArray : array [0..99] of real;


BEGIN
    while (true) do //цикл вводу кількості елементів
    begin
        write('Введіть кількість елементів у масиві, діапазон [5; 100]: ');

        readln(CounterMyArray);

        if( (CounterMyArray >= 5) and (CounterMyArray <= 100) )
        then
        begin
            break; //вихід з циклу
        end
        else
        begin
            writeln('   ', 'Введіть діапазон [5; 100]');
            writeln();
            writeln();
        end;
    end;

    //ввід елементів масиву
    writeln();
    writeln();
    writeln('Ввід масиву:');
    
    for i : integer := 0 to (CounterMyArray - 1) do
    begin
        write('   ', 'елемент №', i + 1, ': ');
        
        readln(MyArray[i]);
    end;
    
    writeln();
    writeln();

    SummPlus := 0; 
    SummMinus := 0;

    for i : integer := 0 to (CounterMyArray - 1) do //цикл пошуку
    begin
        if (MyArray[i] > 0) then
        begin
            SummPlus := SummPlus + MyArray[i];
        end
        else
        begin
            SummMinus := SummMinus + MyArray[i];
        end;
    end;

    writeln('Результати:');
    writeln('   ', 'Сума додатніх чисел: ', SummPlus);
    writeln('   ', 'Сума від`ємних чисел: ', SummMinus);
    writeln('   ', 'Модуль(додатні) - модуль(від`ємні): ', abs(SummPlus) - abs(SummMinus));
    
    readkey();
END.