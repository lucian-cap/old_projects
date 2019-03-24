create schema companyDB;

create table Employee(
Fname varchar(15),
Lname varchar(15),
SSN char(9) not null,
Bdate Date,
Address varchar(30),
Sex  char(1),
Salary int,
SuperSSN varchar(9),
Dno int,
primary key(SSN));

create table Department(
Dname varchar(15),
Dnumber int,
MgrSSN varchar(9),
Mgr_startDate Date,
primary key(Dnumber));

create table DeptLocations(
Dnumber int,
Dlocation varchar(30),
primary key(Dnumber, Dlocation));

create table Project(
Pname varchar(15),
Pnumber int,
Plocation varchar(30),
Dnum int,
primary key(Pnumber));

create table WorksOn(
Essn char(9),
Pno int,
Hours int,
primary key(Essn, Pno));

create table Dependent(
Essn char(9),
DependentName varchar(15),
Sex char(1),
Bdate Date,
Relationship varchar(10));

insert into Employee values('John', 'Smith', '123456789', '1965-01-09', '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);
insert into Employee values('Franklin', 'Wong', '333445555', '1955-12-08', '638 Voss, Houston, TX', 'M', 40000, '888665555', 5);
insert into Employee values('Alicia', 'Zelaya', '999887777', '1968-01-19', '3311 Castle, Spring, TX', 'F', 25000, '987654321', 4);
insert into Employee values('Jennifer', 'Wallace', '987654321', '1941-06-20', '291 Berry, Bellaire, TX', 'F', 43000, '888665555', 4);
insert into Employee values('Ramesh', 'Narayan', '666884444', '1962-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5);
insert into Employee values('Joyce', 'English', '453453453', '1972-07-31', '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5);
insert into Employee values('Jabbar', 'Ahmad', '987987987', '1969-03-29', '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4);
insert into Employee values('James', 'Borg', '888665555', '1937-11-10', '450 Stone, Houston, TX', 'M', 55000, NULL, 1);

insert into Department values('Research', 5, '333445555', '1988-05-22');
insert into Department values('Administration', 1, '987654321', '1995-01-01');
insert into Department values('Headquarters', 4, '888665555', '1981-06-19'); 

insert into DeptLocations values(1, 'Houston');
insert into DeptLocations values(4, 'Stafford');
insert into DeptLocations values(5, 'Bellaire');
insert into DeptLocations values(5, 'Sugarland');
insert into DeptLocations values(5, 'Houston');

insert into Project values('ProductX', 1, 'Bellaire', 5);
insert into Project values('ProductY', 2, 'Sugarland', 5);
insert into Project values('ProductZ', 3, 'Houston', 5);
insert into Project values('Computerization', 10, 'Stafford', 4);
insert into Project values('Reorganization', 20, 'Houston', 1);
insert into Project values('NewBenefits', 30, 'Stafford', 4);

insert into WorksOn values('123456789', 1, 32.5);
insert into WorksOn values('123456789', 2, 7.5);
insert into WorksOn values('666884444', 3, 40.0);
insert into WorksOn values('453453453', 1, 20.0);
insert into WorksOn values('453453453', 2, 20.0);
insert into WorksOn values('333445555', 2, 10.0);
insert into WorksOn values('333445555', 3, 10.0);
insert into WorksOn values('333445555', 10, 10.0);
insert into WorksOn values('333445555', 20, 10.0);
insert into WorksOn values('999887777', 30, 30.0);
insert into WorksOn values('999887777', 10, 10.0);
insert into WorksOn values('987987987', 10, 35.0);
insert into WorksOn values('987987987', 30, 5.0);
insert into WorksOn values('987654321', 30, 20.0);
insert into WorksOn values('987654321', 20, 15.0);
insert into WorksOn values('888665555', 20, NULL);

insert into Dependent values('333445555', 'Alice', 'F', '1986-04-05', 'Daughter');
insert into Dependent values('333445555', 'Theodore', 'M', '1983-10-25', 'Son');
insert into Dependent values('333445555', 'Joy', 'F', '1958-05-03', 'Spouse');
insert into Dependent values('987654321', 'Abner', 'F', '1942-02-28', 'Spouse');
insert into Dependent values('123456789', 'Michael', 'M', '1988-01-04', 'Son');
insert into Dependent values('123456789', 'Alice', 'F', '1988-12-30', 'Daughter');
insert into Dependent values('123456789', 'Elizabeth', 'F', '1967-05-05', 'Spouse');

alter table Employee
add constraint fk_Dno
foreign key(Dno)
references Department(Dnumber);

alter table Department
add foreign key(MgrSSN)
references Employee(SSN);

alter table DeptLocations
add foreign key(Dnumber)
references Department(Dnumber);

alter table Project
add foreign key(Dnum)
references Department(Dnumber);

alter table WorksOn
add foreign key(Essn) references Employee(SSN),
add foreign key(Pno) references Project(Pnumber);

alter table Dependent
add foreign key(Essn)
references Employee(SSN);