create schema COMPANY_caleb_chase;

create table COMPANY_caleb_chase.DEPARTMENT
	(Dname			varchar(15)			not null,
    Dnumber			int					not null,
    Mgr_ssn			char(9)				not null,
    mgr_start_date	date,				
    primary key(Dnumber),
    unique(Dname)
    );
    
create table COMPANY_caleb_chase.EMPLOYEE
	(Fname			varchar(15)			not null,
    Minit			varchar(15)			not null,
    Lname			varchar(15)			not null,
    Ssn				char(9)				not null,
    Bdate			date				not null,
    Address			varchar(35)			not null,
    Sex				char(1)				not null,
    Salary			int					not null,
    Super_ssn		char(9),
    Dno				int					not null,
    primary key(Ssn),
    unique(Ssn)
    );
    
create table COMPANY_caleb_chase.DEPT_LOCATIONS
	(Dnumber	int		not null,
    Dlocation	varchar(20)	not null,
    primary key(Dnumber, Dlocation)
    );

create table COMPANY_caleb_chase.WORKS_ON
	(Essn		char(9)		not null,
    Pno			int			not null,
    Hours		int,
    primary key(Essn, Pno)
    );
    
create table COMPANY_caleb_chase.PROJECT
	(Pname		varchar(25)		not null,
    Pnumber		int				not null,
    Plocation	varchar(20)		not null,
    Dnum		int				not null,
    primary key(Pnumber)
    );
    
create table COMPANY_caleb_chase.DEPENDENT
	(Essn			char(9)			not null,
    Dependent_name	varchar(25)		not null,
    Sex				char(1)			not null,
    Bdate			date			not null,
    Relationship	varchar(15)		not null,
    primary key(Essn, Dependent_name)
    );
    
insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values ('John', 'B', 'Smith', 123456789, '1965-01-09', '731 Fondren, Houston, TX', 'M', 30000, 333445555, 5);

insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values ('Franklin', 'T', 'Wong', 333445555, '1955-12-08', '638 Voss, Houston, TX', 'M', 40000, 888665555, 5);

insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values ('Alicia', 'J', 'Zelaya', 999887777, '1968-01-19', '3321 Castle, Spring, TX', 'F', 25000, 987654321, 4);

insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values ('Jennifer', 'S', 'Wallace', 987654321, '1941-06-20', '291 Berry, Bellaire, TX', 'F', 43000, 888665555, 4);

insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values ('Ramesh', 'K', 'Narayan', 666884444, '1962-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, 333445555, 5);

insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values ('Joyce', 'A', 'English', 453453453, '1972-07-31', '5631 Rice, Houston, TX', 'F', 25000, 333445555, 5);

insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values ('Ahmed', 'V', 'Jabber', 987987987, '1969-03-29', '980 Dallas, Houston, TX', 'M', 25000, 987654321, 4);

insert into COMPANY_caleb_chase.employee(Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Dno)
values ('James', 'E', 'Borg', 888665555, '1937-11-10', '450 Stone, Houston, TX', 'M', 55000, 1);

insert into COMPANY_caleb_chase.department(Dname, Dnumber, Mgr_ssn, Mgr_start_date)
values ('Research', 5, 333445555, '1988-05-22');

insert into COMPANY_caleb_chase.department(Dname, Dnumber, Mgr_ssn, Mgr_start_date)
values ('Administration', 4, 987654321, '1995-01-01');

insert into COMPANY_caleb_chase.department(Dname, Dnumber, Mgr_ssn, Mgr_start_date)
values ('Headquarters', 1, 888665555, '1988-06-19');

insert into company_caleb_chase.dept_locations(Dnumber, Dlocation)
values (1, 'Houston');

insert into company_caleb_chase.dept_locations(Dnumber, Dlocation)
values (4, 'Stafford');

insert into company_caleb_chase.dept_locations(Dnumber, Dlocation)
values (5, 'Bellaire');

insert into company_caleb_chase.dept_locations(Dnumber, Dlocation)
values (5, 'Sugarland');

insert into company_caleb_chase.dept_locations(Dnumber, Dlocation)
values (5, 'Houston');

insert into company_caleb_chase.project(Pname, Pnumber, Plocation, Dnum)
values ('ProductX', 1, 'Bellaire', 5);

insert into company_caleb_chase.project(Pname, Pnumber, Plocation, Dnum)
values ('ProductY', 2, 'Sugarland', 5);

insert into company_caleb_chase.project(Pname, Pnumber, Plocation, Dnum)
values ('ProductZ', 3, 'Houston', 5);

insert into company_caleb_chase.project(Pname, Pnumber, Plocation, Dnum)
values ('Computerization', 10, 'Stafford', 4);

insert into company_caleb_chase.project(Pname, Pnumber, Plocation, Dnum)
values ('Reorganization', 20, 'Houston', 1);

insert into company_caleb_chase.project(Pname, Pnumber, Plocation, Dnum)
values ('Newbenefits', 30, 'Stafford', 4);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (123456789, 1, 32.5);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (123456789, 2, 7.5);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (666884444, 3, 40.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (453453453, 1, 20.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (453453453, 2, 20.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (333445555, 2, 10.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (333445555, 3, 10.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (333445555, 10, 10.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (333445555, 20, 10.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (999887777, 30, 30.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (999887777, 10, 10.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (987987987, 10, 35.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (987987987, 30, 5.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (987654321, 30, 20.0);

insert into company_caleb_chase.works_on(Essn, Pno, Hours)
values (987654321, 20, 15.0);

insert into company_caleb_chase.works_on(Essn, Pno)
values (888665555, 20);

insert into company_caleb_chase.dependent(Essn, Dependent_name, Sex, Bdate, Relationship)
values (333445555, 'Alice', 'F', '1986-04-05', 'Daughter'), 
	   (333445555, 'Theodore', 'M', '1983-10-25', 'Son'),
       (333445555, 'Joy', 'F', '1958-05-03', 'Spouse'),
       (987654321, 'Abner', 'M', '1942-02-28', 'Spouse'),
       (123456789, 'Michael', 'M', '1988-01-04', 'Son'),
       (123456789, 'Alice', 'F', '1988-12-30', 'Daughter'),
       (123456789, 'Elizabeth', 'F', '1967-05-05', 'Spouse');

alter table company_caleb_chase.department add constraint fk_Mgr_ssn
foreign key (Mgr_ssn) references EMPLOYEE (Ssn);

alter table company_caleb_chase.EMPLOYEE add constraint fk_Dno
foreign key (Dno) references department(Dnumber);

alter table company_caleb_chase.employee add constraint fk_Super_ssn
foreign key (Super_ssn) references employee (Ssn);

alter table company_caleb_chase.works_on add constraint fk_Essn
foreign key (Essn) references employee (Ssn);

alter table company_caleb_chase.dept_locations add constraint fk_Dnumber
foreign key (Dnumber) references Department (Dnumber);

alter table company_caleb_chase.project add constraint fk_Dnum
foreign key (Dnum) references department (Dnumber);

alter table company_caleb_chase.works_on add constraint fk_Pno
foreign key (Pno) references project (Pnumber);

alter table company_caleb_chase.dependent add constraint fk_Essn_dependent
foreign key (Essn) references employee (Ssn);


