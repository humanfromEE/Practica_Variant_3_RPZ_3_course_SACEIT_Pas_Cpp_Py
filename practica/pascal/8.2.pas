USES
    crt;

VAR
    ArrayKopalin : array [1..15] of string;
    First, Second, Third, Fourth, Fifth : set of string;

//заповнення множин
PROCEDURE ProcInputSet(var ArgSet : set of  string);
begin
    for i : integer := 1 to 10 do
    begin
        include(ArgSet, ArrayKopalin[random(15) + 1]);
    end;
end;

//вивід множини
PROCEDURE ProcOutputSet(Message : string; Argset : set of string);
begin
    writeln(Message, ':');
    writeln('    ', Argset);
    writeln();
    writeln();
end;

BEGIN
    //заповнення масиву копалин
	ArrayKopalin[1] := 'nafta';
    ArrayKopalin[2] := 'zoloto';
    ArrayKopalin[3] := 'vugillya';
    ArrayKopalin[4] := 'diamanti';
    ArrayKopalin[5] := 'gaz';
    ArrayKopalin[6] := 'ryda';
    ArrayKopalin[7] := 'pisok';
    ArrayKopalin[8] := 'zemlya';
    ArrayKopalin[9] := 'granit';
    ArrayKopalin[10] := 'slanets';
    ArrayKopalin[11] := 'aluminiy';
    ArrayKopalin[12] := 'bronza';
    ArrayKopalin[13] := 'byrshtin';
    ArrayKopalin[14] := 'izumrud';
    ArrayKopalin[15] := 'svinets';
    
    //заповнення множин
    ProcInputSet(First);
    ProcInputSet(Second);
    ProcInputSet(Third);
    ProcInputSet(Fourth);
    ProcInputSet(Fifth);
    
    //вивід множин
    ProcOutputSet('перша множина', First);
    ProcOutputSet('друга множина', Second);
    ProcOutputSet('третя множина', Third);
    ProcOutputSet('четверта множина', Fourth);
    ProcOutputSet('п`ята множина', Fifth);
    
    //вивід елементів які є у всіх множинах
    writeln('копалини, які є у всіх множинах:');
    for i : integer := 1 to 15 do
    begin
        if
        (
            (ArrayKopalin[i] in First) and (ArrayKopalin[i] in Second) and
            (ArrayKopalin[i] in Third) and (ArrayKopalin[i] in Fourth) and
            (ArrayKopalin[i] in Fifth)
        ) 
		then
        begin   
            writeln('    ', ArrayKopalin[i]);
        end;
    end;
    
    writeln();
    writeln();
    
    //вивід елементів яких немає у множинах
    writeln('копалини, яких немає у множинах:');
    for i : integer := 1 to 15 do
    begin
        if
        (
            (
                (ArrayKopalin[i] in First) or (ArrayKopalin[i] in Second) or
                (ArrayKopalin[i] in Third) or (ArrayKopalin[i] in Fourth) or
                (ArrayKopalin[i] in Fifth) 
            ) = false
        ) 
		then
        begin   
            writeln('    ', ArrayKopalin[i]);
        end;
    end;
    
    writeln();
    writeln();
    
    //додаткове завдання - елементи, які є лише у першій множині
    writeln('копалини, які є лише у першій множині:');
    
    foreach i : string in First do
    begin
        if
        (
            (
                (i in Second) or (i in Third) or 
                (i in Fourth) or (i in Fifth) 
            ) = false
        ) 
		then
        begin   
            writeln('    ', i);
        end;
    end;
    
    readkey();
END.