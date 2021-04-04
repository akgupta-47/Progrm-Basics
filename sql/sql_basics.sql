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
Insert into Student values(3783 ,'shubham','30-april-2002','Male','B-Tech','TIET','Patiala',88);
Insert into Student values(3784 ,'Akshat','21-feb-2002','Male','B-Tech','TIET','Patiala',90);
insert into Student(firstname) values('david dobrik');
select * from student where city='Patiala';
DELETE FROM student WHERE firstname='david dobrik'; 
delete from student where marks<=30;
delete from student where city='Amritsar';
select firstname from Student;
--describe student schema
desc Student
--order elements asc|desc
select * from student;
order by marks asc;
--update documents
update student
set marks=67 , rollNumber=78
where firstname='david dobrik';
select * from Student;

select * from Student where firstname like 'david%';
select * from Student where marks>=89;
select * from Student;


select sysdate+1 from dual
---dual is a dummy table
select (sysdate-dob)/365 from student --- lets say answer comes 40.26.... so here 26 means 26% of that year was passed too
select (sysdate-dob)/365 as age from student
select to_char(sysdate, 'dd/mm/yyyy hh24:mi:ss') from dual;
insert into stu values(1, to_date('12-dec-1980 6:00', 'dd-mon-yyyy hh24:mi' ));
/* Mon for Mar, MON for MAR , Month fro March*/
/* when specifying date, it keeps 00:00:00 as default time*/
/* by default select karne p time nahi bata h*/
select rno, to_char(dob, 'mm/dd/yyyy hh24:mi:ss') from stu;
select rno, to_char(dob, 'hh24:mi:ss') from stu; --- if we want to only display time
select to_char(sysdate +1/48, 'dd/mm/yyyy hh24:mi:ss') from dual; --- this adds half hour to time (1day / 24 hrs to add 1 hr, 1day/ 2*24 hours to add half hour  
---insert karte waqt to_date aur display karte hue to_char
--- to find train departing in next 1hr = where arr <= sysdate + 1/24
--- where dep between sysdate and sysdate + 1/24;
--- sysdate-departure < 1/24
--- ddspth day year yyyy DY = ninth tuesday twenty twenty-one 2021 TUE
--- am ya pm k liye koi daldo as format specifier, it will figure it out on its own

-- assign 2
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
insert into emp values(125, 'brimstone', 'muscle', 8000, 56);
select empno, ename from emp where deptno=10;
select ename from emp where salary>10000;
select deptno, salary from emp order by deptno asc,salary desc;
select * from emp where salary between 9000 and 13000;
select deptno, salary from emp
order by salary asc;
insert into emp values(126, 'carly', 'vlog', 7000, 38);
select * from emp where ename like 'c%';
insert into emp values(126, 'barc', 'pet detective', 19000, 90);
insert into emp values(126, 'bacodi', 'jobless', 1000, 1);
select * from emp where ename like '%c%';
insert into emp values(128, 'jamacob', 'singer', 30000, 67);
insert into emp values(129, 'jAmAcob', 'singer', 31000, 68);
SELECT ename FROM emp WHERE ename LIKE '%a%a%' or ename like '%A%A%';
SELECT ename FROM emp WHERE substr(ename,2,1) like 'a' or substr(ename,2,1) like 'A' ;
SELECT ename FROM emp WHERE substr(ename,2,1) like 'a' or substr(ename,1,1) like 'A' ;
insert into emp values(128, 'liverpoolA', 'footbaler', 300000, 80);
insert into emp values(128, 'aztec', 'priest', 2000, 1000);
SELECT ename FROM emp WHERE substr(ename,1,1) like 'a' or substr(ename,1,1) like 'A' or substr(ename,length(ename),1) like 'A' or substr(ename,length(ename),1) like 'a' ;
--order by dept asc, salary desc


-------------------------------------------------------------------------------------------------------
-- assignment 3
select sysdate+1 from dual;
select to_char(sysdate, 'dd/mm/yyyy hh24:mi:ss') from dual;
select to_char(sysdate + 1/12, 'dd/mm/yyyy hh24:mi:ss') from dual;
select to_char(sysdate + 1/48, 'dd/mm/yyyy hh24:mi:ss') from dual;
select to_char(sysdate,'day')from dual;
select to_char(sysdate+2, 'dd/mm/yyyy hh24:mi:ss') from dual;
select to_char(sysdate, 'mm/year') from dual;
select to_char(sysdate, 'ddspth/month/year') from dual;
select to_char(sysdate+11/48, 'pm') from dual;
select round(sysdate, 'MONTH') from dual;
select trunc(sysdate, 'month') from dual;
select round(sysdate, 'YEAR') from dual;
select trunc(sysdate, 'year') from dual;
select to_char(sysdate+3, 'day') from dual;
select months_between(to_date('12-dec-2003', 'dd-mon-yyyy' ), to_date('12-feb-2004', 'dd-mon-yyyy' )) as diffMonth from dual;
select last_day(to_char('12-12-2003', 'day')) from dual;
select next_day(sysdate, 'friday') as nextFriday from dual;
--------------------------------------------------------------------------------
create table studs
(
    roll int,
    dob date
);
insert into studs values(1, to_date('12-dec-2003 6:12', 'dd-mon-yyyy hh24:mi' ));
insert into studs values(1, '1-dec-2000');
insert into studs values(1, to_date('6:12', 'hh24:mi' ));
insert into studs values(3, to_date('5-Apr-2021', 'dd-Mon-yyyy'));
select to_char(dob, 'dd/mm/yyyy hh24:mi:ss') from studs;
select dob, to_char(dob,'hh24')as time from studs where roll=1; 
select DOB, to_char(DOB,'dd/mm/yyyy hh24:mi:ss AM')as DOB from studs where roll=3; 
--delete studs
select * from studs where to_char(dob,'mon')='apr';
select * from studs where trim(to_char(dob,'Day'))='Monday';
select * from studs where trim(to_char(dob,'month'))=trim(to_char(sysdate,'month'));
select * from studs where  dob  >=  SYSDATE - 30 AND  dob  <   SYSDATE;
select * from studs where round((sysdate-dob)/365)<16.5;
select round((sysdate-dob)) as age from studs;
select round((sysdate-dob)/365) as ageinyears from studs;
--------------------------------------------------------------------------------
create table Train(
    trainNo number(10), 
    dep date, 
    arrival date
);
insert into Train values(12345,to_date('29-August-2020 8:00 AM','dd-mm-yyyy hh:mi AM'),to_date('2-September-2020 11:23 AM','dd-mm-yyyy hh:mi AM')); 
insert into Train values(12665,to_date('27-March-2021 11:00 AM','dd-mm-yyyy hh:mi AM'),to_date('2-April-2021 10:40 PM','dd-mm-yyyy hh:mi PM'));  
insert into Train values(12665,to_date('7-March-2021 12:00 AM','dd-mm-yyyy hh:mi AM'),to_date('3-April-2021 12:40 PM','dd-mm-yyyy hh:mi PM'));  
insert into Train values(12665,to_date('21-March-2021 6:00 AM','dd-mm-yyyy hh:mi AM'),to_date('29-March-2021 10:40 AM','dd-mm-yyyy hh:mi PM'));  
insert into Train values(12665,to_date('24-June-2020 1:00 AM','dd-mm-yyyy hh:mi AM'),to_date('2-July-2020 11:40 PM','dd-mm-yyyy hh:mi PM'));  
insert into Train values(12669,to_date('04-April-2021 15:00','dd-mm-yyyy hh24:mi'),to_date('04-April-2021 13:00','dd-mm-yyyy hh24:mi'));  
select * from Train;
select trainNo, to_char(dep,'dd-mon-yyyy hh24:mi AM')as dep, to_char(arrival, 'dd-mon-yyyy hh24:mi AM') as arrival from Train;
select * from Train where trim(to_char(arrival,'AM'))='PM';
select trainNo from Train where dep between sysdate and sysdate+1/24;
select trainNo from Train where dep between sysdate and sysdate+1/48;

---------------------------------------------------------------------------------------------------
-- assignment 4
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
--delete from student;
Insert into Student values(3782 ,'rashil','30-march-2002','Male','B-Tech','TIET','Patiala',89);
Insert into Student values(3783 ,'shubham','30-april-2002','Male','B-Tech','TIET','Patiala',88);
select chr(71) as dummyCharacter from dual;
select concat('YE',' humari') as pawri from dual;
select * from student;
select instr(firstname, 'a') from student;
select length(firstname) from student;
select lpad(firstname,20,'pawri') from student;
select ltrim('        pawri') from student;
select ltrim('pppaawri', 'pa') from student;
select replace('mumbai indians won the ipl','mumbai indians','Rajasthan royals') from student;
select substr(firstname, 2,3) from student;
select * from user_contraints where table_name = 'Employee';
select initcap('i saw rajathan royals win ipl') from dual;
select lower('RCB WAS RUNNER UP OF IPL') as jokes from dual;
select upper('liverpool won the champions league') as champions from dual;
select translate('real kardrid are noob','k','m') as noob from dual;
select abs(-34) as thirtyFive from dual;
select ceil(34.35) as thirtyFour from dual;
select cos(0) as horizontalLine from dual;
select exp(1) as exponent from dual;
select floor(35.34) as zameeen from dual;
select mod(9,2) as remainders from dual;
select power(3,4) as takat from dual;
select round(787.456, 1) as kata from dual;
select sign(-56) as negPos from dual;
select sqrt(49) as chota from dual;
select trunc(567.78,0) as trunc from dual;
select sysdate as today from dual;
select add_months(sysdate, 2) as dayAfterTommorow from dual;
select last_day('4-apr-2021') as lastDay from dual;
select round(months_between(sysdate, '27-nov-2020')) as monthsBetween from dual;
select next_day(sysdate, 'THURSDAY') as nextThursday from dual;
select greatest(56,34,35,6,8) as victorious from dual;
select least(56,34,35,6,8) as noob from dual;





select deptno,count(*) from employee where group by deptno order by deptno;
select sum(salary) Total_salary from employee where job <> 'Prof' group by Dept;
select avg(salary) Average_salary from employee where job <> 'Prof' group by Dept;
select deptno,job,sum(salary) from employee group by deptno,job;
select deptno,job,sum(salary) from employee group by deptno; --this won't work as if u want to select job thn u have to group data by it too
select deptno,job,sum(salary) from employee where job <> 'AssocProf' group by deptno;
-- to restrict data or perform on data after grouping we cannot use 'where' so we use 'having'
select deptno,sum(salary) totalSalary from employee group by deptno having(totalSalary) > 16000;	
-- we can write having clause before group by but logically it is preffered to have it after
-- constraints are not null,unique(multpli null is allowed),
-- we can also specify constraints using unique(roll_no,class) and we can assignit a name by constraint rno_class_unique unique(roll_no,class);
-- we can repeat either of one in one row but we cannot repeat them for same row
-- primary key is unique and not null
constraint check_class check (class in ('bed','bcom','btech')), (case sensetive)
check (marks >= 0)
-- don't use check constraints if the values will change in future
-- foreign key can be single or mutiple columns, child tabel is one that contains foreign key and parent has primary key
create table department (
deptno number(2) primary key,
dname char(20) 
);
create table employee (
eno number(2) primary key,
ename char(20),
job char)10),
deptno number(2) refrences department(deptno)
);
-- on delete cascade the entry is removed from both the tabels
-- on delete set null , removed from refrence table(parent department) but value of foreign key set to null in main table(employee child)
-- we can set at end of table creation on delete cascade
alter table student add (address varchar(20), name varchar(10));
alter table student add primary key (roll_number);
alter table student add foreign key (class) refrencees class_detail(class);
-- alter size from 15, but when decreasing size mind it that some values can of higher size and size reduction is only allowed for char and varchar, for any other data type like number we have to empty al columns first
alter table student modify name char(20);
-- alter datatype 
alter table student modify name varchar(20);
alter table student drop primary key
alter table student drop column mobile-no
--------------------------------------------------------------------------------------------------------------------
-- assignment 5
create table department(
    deptno int,
    dname varchar(20) check (dname in('Acc','comp','elect')),
    CONSTRAINT PK_Deptno PRIMARY KEY (deptno)
);

CREATE TABLE emp(
    empno INT,
    ename VARCHAR(15),
    job varchar(20) check(job in('Prof','AP','Lect')),
    sal INT NOT NULL,
    deptno INT,
    CONSTRAINT PK_Dept PRIMARY KEY (empno),
    CONSTRAINT FK_employee FOREIGN KEY (deptno) REFERENCES department(deptno),
    CONSTRAINT UC_ename UNIQUE (ename)
);

create table salesperson(
    sno int primary key,
    sname varchar(10),
    city varchar(10)
);
create table part(
    pno int primary key,
    pname varchar(10),
    color varchar(10)
);

create table ProJect(
    jno int primary key,
    jname varchar(10),
    city varchar(10)
);
create table spj(
    










