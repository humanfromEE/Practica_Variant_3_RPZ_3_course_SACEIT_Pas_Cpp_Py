USES 
    GraphABC;

VAR
    x, y, h:real;
    Counter, i : integer;

BEGIN
    //налаштування вікна і осей
    setWindowSize(500, 500);
    
    line(0, 250, 500, 250); //Ox
    line(480, 240, 500, 250);
    line(480, 260, 500, 250);
    textout(485, 220, 'X');
    
    line(250, 0, 250, 500); //Oy
    line(250, 0, 240, 20);
    line(250, 0, 260, 20);
    textout(265, 5, 'Y');
    
    //вивід штрихованого відрізку [0; 2п]
    textout(240, 255, '0');
    textout(round(240 + 2 * pi * 30), 255, '2п');

    Counter := 1;
    i := 0;
    while (i < 490) do
    begin
        if (Counter mod 2 <> 0) then
        begin
            line(round(250 + 2 * pi * 30), i, round(250 + 2 * pi * 30), i + 10);
        end;
        
        Counter := Counter + 1;
        i := i + 10;
    end;
    
    x := 0;
    y := power(x, 1.0 / 3) + power( sin(x), 2);
    h := 0.01;
    
    while ( (x >= 0) and ( x <= (2 * pi) ) ) do
    begin
        setpixel(round(250 + x * 30),round(250 - y * 30),clRed); //я домножив на 30, щоб збільшити масштаб графіку функції
        y := power(x, 1.0 / 3) + power( sin(x), 2);
        x := x + h;
    end;
END.