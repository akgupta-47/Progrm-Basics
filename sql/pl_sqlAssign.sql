create table Student
(
    rollNumber int,
    firstname varchar(15),
    DOB date,
    Gender varchar(7),
    Batch varchar(10),
    College varchar(20),
    City varchar(16),
    Marks int
);

Insert into Student values(3782 ,'rashil','30-march-2002','Male','B-Tech','TIET','Patiala',89);
Insert into Student values(3782 ,'shubham','30-april-2002','Male','B-Tech','TIET','Patiala',88);
Insert into Student values(3782 ,'bigfoot','22-jan-2002','Male','B-Tech','TIET','Patiala',96);
Insert into Student values(3784 ,'Akshat','21-feb-2002','Male','B-Tech','TIET','Patiala',90);

declare
v_student number;

begin

select marks into v_student from student where rollNumber=3785;

end;

declare
    stud student%rowtype;
begin
    select * into stud from student where rollNumber=3785;
exception
    when no_data_found then dbms_output.put_line('NO DATA FOUND');
    when too_many_rows then dbms_output.put_line('TOO MANY ROWS');
end;

Declare
  n_count number;
Begin
  Select count(1) into n_count 
   from student
   Where college = 'TIET';

  if n_count > 0 then
    dbms_output.put_line('record exists.');
  else
    dbms_output.put_line('record does not exists.');
  end if;
End;

declare
begin
delete from student where dob='21-feb-2002';
delete from student where dob='22-jan-2002';
dbms_output.put_line('the rows :' || sql%rowcount);
end;

select * from student where dob='21-feb-2002';

create table emp(
    empno int,
    ename varchar(15),
    job varchar(20),
    salary int,
    deptno int
);
insert into emp values(123, 'jett', 'air bender', 12000, 34);
insert into emp values(124, 'omen', 'shadow', 15000, 20);
insert into emp values(124, 'sova', 'shock', 10000, 10);
insert into emp values(123, 'voper', 'poisionous', 15000, 39);
insert into emp values(125, 'brimstone', 'muscle', 8000, 56);

declare
no int;
name varchar(15);
work varchar(20);
begin
select empno, ename, job into no,name,work from emp where deptno=10;
dbms_output.put_line('the row :' || no || ' ' || name || ' ' || work);
end;

DECLARE
CURSOR C1 IS SELECT empno,ename FROM Emp order by salary desc;
eno emp.empno%type;
e_name emp.ename%type;
BEGIN
OPEN C1;
LOOP
FETCH C1 INTO
eno,e_name ;
EXIT WHEN (C1%ROWCOUNT >5) or (C1%NOTFOUND);
dbms_output.put_line('the row :' || eno || ' ' || e_name );
-- INSERT INTO temp VALUES (eno,e_name);
COMMIT;
END LOOP;
end;

create table cust(
cno int,
meterno int,
prevR int,
currR int,
units int,
bill_amount float
);
insert into cust values(89,100,300,800,null,null);
insert into cust values(67,101,790,1000,null,null);
insert into cust values(90,200,800,1200,null,null);
insert into cust values(70,899,3200,8700,null,null);

declare 
unts int;
prev int;
curr int;
bill float;
r_cust cust%rowtype;
begin
select prevR, currR,units, bill_amount into prev,curr,unts,bill from cust where cno=89;
unts := curr - prev;
bill := 100*0.5 + (unts-100)*0.75;
update cust set cust.units=unts , cust.bill_amount=bill where cno=89;
select * into r_cust from cust where cno=89;
dbms_output.put_line('the row : ' || r_cust.units || ' ' || r_cust.bill_amount );
end;

select * from cust;
update cust set units=null, bill_amount=null where cno=89;

declare
CURSOR C1 IS SELECT prevR,currR,units,bill_amount, cno FROM cust;
unts int;
prev int;
curr int;
bill float;
csmthng int;
r_cust cust%rowtype;
begin
    open C1;
    Loop
    fetch C1 into prev, curr, unts, bill, csmthng;
        --dbms_output.put_line('the row : ' || unts || ' ' || bill || ' ' || prev || ' ' ||curr || ' ' || csmthng );
        exit when C1%notfound;
        unts := curr - prev;
        bill := 100*0.5 + (unts-100)*0.75;
        update cust set cust.units=unts , cust.bill_amount=bill where cno=csmthng;
        select * into r_cust from cust where cno=csmthng;
        dbms_output.put_line('the row : ' || r_cust.units || ' ' || r_cust.bill_amount );
        commit;
    end loop;
    close C1;
end;

-------------------------- assign 2
create table book(
rno number(3),
bookno number (7),
doi date,
dor date,
fine number(5)
);

Insert into book values(111,42,'06-jan-2021','05-jan-2021',null);
Insert into book values(100,49,'22-jan-2021','18-feb-2021',null);
update
select *from book;

Declare
    deNum number;
    drNum number;
    meNum number;
    mrNum number;
    varNum number;
    sub number;
Begin
    select to_char(doi,'dd') into deNum from book where rno = 100;
    select to_char(dor,'dd') into drNum from book where rno = 100;
    select to_char(doi,'mm') into meNum from book where rno = 100;
    select to_char(dor,'mm') into mrNum from book where rno = 100;
    
    if meNum=mrNum then
        sub:=drNum-deNum;
        if sub<=7 then
            varNum:=sub*1;
        elsif sub<=14 then
            varNum:=7+((sub-7)*2);
        else
            varNum:= 7+14+((sub-14)*3);
        end if;
    else
        sub:=mrNum-meNum;
        sub:=sub*30;
        sub:= sub + (drNum-deNum);
        
        varNum:= 7+14+((sub-14)*3);
    end if;
    
    update book set fine=varNum where rno=100;
    dbms_output.PUT_LINE('Fine is : '||varNum);
end;



