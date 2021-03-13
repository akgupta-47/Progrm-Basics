/*
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
DELETE FROM student WHERE firstname='david dobrik'; 
select firstname from Student;
desc Student
*/
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


