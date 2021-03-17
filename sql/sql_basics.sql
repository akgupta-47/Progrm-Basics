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


////////////////////////////////
select sysdate+1 from dual;
select to_char(sysdate, 'dd/mm/yyyy hh24:mi:ss') from dual;
select to_char(sysdate + 11/48, 'dd/mm/yyyy hh24:mi:ss') from dual;
select to_char(sysdate+2, 'dd/mm/yyyy hh24:mi:ss') from dual;
select to_char(sysdate, 'mm/year') from dual;
select to_char(sysdate, 'ddspth/month/year') from dual;
select to_char(sysdate+11/48, 'pm') from dual;
select round(sysdate, 'MONTH') from dual;
select trunc(sysdate, 'month') from dual;
select round(sysdate, 'YEAR') from dual;
select trunc(sysdate, 'year') from dual;
select to_char(sysdate+3, 'day') from dual;



///////////////////////////////////
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
delete from student;
Insert into Student values(3782 ,'rashil','30-march-2002','Male','B-Tech','TIET','Patiala',89);
Insert into Student values(3783 ,'shubham','30-april-2002','Male','B-Tech','TIET','Patiala',88);
select concat('YE','humari') from student;
select * from student;
select instr(firstname, 'a') from student;
select length(firstname) from student;
select lpad(firstname,20,'pawri') from student;
select ltrim('        pawri') from student;
select ltrim('pppaawri', 'pa') from student;
select replace('teacher ki pawri ho rahi h','teacher','student') from student;
select substr(firstname, 2,3) from student;

