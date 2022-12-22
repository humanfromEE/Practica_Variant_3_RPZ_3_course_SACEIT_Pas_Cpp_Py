USES
    crt;

VAR
    Xmin, Xmax, Xstep, x, y : real;

LABEL 
    IfLabel;
    
BEGIN
    //у прикладі не задовільне ОДЗ для заданого діапазону, я долучив для наглядності до числа логарифму модуль
    
    Xmin := 7.5;
    Xmax := 10;
    Xstep := 0.5;
    
    //використанн¤ if (за допомогою goto)
    writeln('Використанн¤ if (за допомогою goto):');
	
	x := Xmin;
    
    IfLabel:
        if (x <= Xmax) then
        begin
            y := log10(  abs( (1 - x) / (1 + x) ) );
            writeln('   ', 'x: ', x, ' => ', 'y: ', y);

            x := x + Xstep;
            
            goto IfLabel;
        end;
        
    //використання циклу while
    writeln();
    writeln('Використання циклу while:');
    
    x := Xmin;
    
    while (x <= Xmax) do
    begin
        y := log10(  abs( (1 - x) / (1 + x) ) );
        writeln('   ', 'x: ', x, ' => ', 'y: ', y);

        x := x + Xstep;
    end;
    
    //використання циклу repeat
    writeln();
    writeln('Використання циклу repeat:');
    
    x := Xmin;
    
    repeat
        y := log10(  abs( (1 - x) / (1 + x) ) );
        writeln('   ', 'x: ', x, ' => ', 'y: ', y);

        x := x + Xstep;
    until (x > Xmax);
    
    //використання циклу for
    writeln();
    writeln('Використання циклу for:');
    
    x := Xmin;
    
    for i : integer := 0 to round((Xmax - Xmin) / Xstep) do
    begin
        y := log10(  abs( (1 - x) / (1 + x) ) );
        writeln('   ', 'x: ', x, ' => ', 'y: ', y);

        x := x + Xstep;
    end;
    
    readkey();
END.