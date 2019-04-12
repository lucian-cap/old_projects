#all information obtained from basketballreference.com
create schema nba_calebwatson_chaseperry;

create table nba_calebwatson_chaseperry.coaches_career(
	coachid varchar(15) primary key not null,
    firstname varchar(15),
    lastname varchar(15),
    season_win int,
    season_loss int,
    playoff_win int,
    playoff_loss int);
    
create table nba_calebwatson_chaseperry.coaches_season(
	coachid varchar(15) not null,
    year_date int not null,
    yr_order int,
    firstname varchar(15),
    lastname varchar(15),
    season_win int,
    season_loss int,
    playoff_win int,
    playoff_loss int,
    team varchar(5) not null,
    primary key(coachid, year_date, team));
    
create table nba_calebwatson_chaseperry.player_allstar(
	ilkid varchar(15) not null,
    year_date year not null,
    firstname varchar(20),
    lastname varchar(25),
    conference varchar(10) not null,
    leag varchar(3),
    gp varchar(2),
    minutes varchar(3) not null,
    pts varchar(3),
    dreb varchar(2),
    oreb varchar(2),
    red varchar(2),
    asts varchar(2),
    stl varchar(2),
    blk varchar(2),
    turnover varchar(2),
    pf varchar(2),
    fga varchar(2),
    fgm varchar(2),
    fta varchar(2),
    ftm varchar(2),
    tpa varchar(2),
    tpm varchar(2),
    primary key(ilkid, year_date, conference, minutes)
);

create table nba_calebwatson_chaseperry.player_playoffs(
	ilkid varchar(15) not null,
    year_date year not null,
    firstname varchar(20),
    lastname varchar(25),
    team varchar(7) not null,
    leag varchar(3) not null,
    gp varchar(4),
    minutes varchar(4),
    pts varchar(4),
    dreb varchar(4),
    oreb varchar(4),
    red varchar(4),
    asts varchar(4),
    stl varchar(4),
    blk varchar(4),
    turnover varchar(4),
    pf varchar(4),
    fga varchar(4),
    fgm varchar(4),
    fta varchar(4),
    ftm varchar(4),
    tpa varchar(4),
    tpm varchar(4),
    primary key(ilkid, year_date, team, leag)
);
    

create table nba_calebwatson_chaseperry.player_playoffs_career(
	ilkid varchar(15) not null,
    firstname varchar(20),
    lastname varchar(25),
    leag varchar(3) not null,
    gp varchar(5),
    minutes varchar(5),
    pts varchar(5),
    dreb varchar(5),
    oreb varchar(5),
    reb varchar(5),
    asts varchar(5),
    stl varchar(5),
    blk varchar(5),
    turnover varchar(5),
    pf varchar(5),
    fga varchar(5),
    fgm varchar(5),
    fta varchar(5),
    ftm varchar(5),
    tpa varchar(5),
    tpm varchar(5),
    primary key(ilkid, leag)
);


create table nba_calebwatson_chaseperry.player_regular_season(
	ilkid varchar(15) not null,
    year_date year not null,
    firstname varchar(20),
    lastname varchar(25),
    team varchar(7) not null,
    leag varchar(3) not null,
    gp varchar(5),
    minutes varchar(5),
    pts varchar(5),
    oreb varchar(5),
    dreb varchar(5),
    reb varchar(5),
    asts varchar(5),
    stl varchar(5),
    blk varchar(5),
    turnover varchar(5),
    pf varchar(5),
    fga varchar(5),
    fgm varchar(5),
    fta varchar(5),
    ftm varchar(5),
    tpa varchar(5),
    tpm varchar(5),
    primary key(ilkid, year_date, team, leag)
);

create table nba_calebwatson_chaseperry.player_regular_season_career(
	ilkid varchar(15) not null,
    firstname varchar(20),
    lastname varchar(25),
    leag varchar(3) not null,
    gp varchar(5),
    minutes varchar(6),
    pts varchar(6),
    oreb varchar(5),
    dreb varchar(5),
    reb varchar(6),
    asts varchar(5),
    stl varchar(5),
    blk varchar(5),
    turnover varchar(5),
    pf varchar(5),
    fga varchar(6),
    fgm varchar(5),
    fta varchar(5),
    ftm varchar(5),
    tpa varchar(5),
    tpm varchar(5),
    primary key(ilkid, leag)
);

create table nba_calebwatson_chaseperry.players(
	ilkid varchar(15) not null,
    firstname varchar(15),
    lastname varchar(25),
    position_ varchar(3),
    firstseason year,
    lastseason year,
    height_feet varchar(2),
    height_inches varchar(4),
    weight varchar(4),
    college varchar(30),
    birthday varchar(20),
    primary key(ilkid)
);
		
        
create table nba_calebwatson_chaseperry.team_season(
	team varchar(5) not null,
	year_date year not null,
	leag varchar(2) not null,
	o_fgm varchar(6),
	o_fga varchar(6),
	o_ftm varchar(6),
	o_fta varchar(6),
	o_oreb varchar(6),
	o_dreb varchar(6),
	o_reb varchar(6),
	o_asts varchar(6),
	o_pf varchar(6),
    o_stl varchar(6),
	o_to varchar(6),
    o_blk varchar(6),
	o_3pm varchar(6),
    o_3pa varchar(6),
	o_pts varchar(6),
    d_fgm varchar(6),
	d_fga varchar(6),
    d_ftm varchar(6),
	d_fta varchar(6),
	d_oreb varchar(6),
	d_dreb varchar(6),
	d_reb varchar(6),
	d_asts varchar(6),
	d_pf varchar(6),
    d_stl varchar(6),
	d_to varchar(6),
    d_blk varchar(6),
	d_3pm varchar(6),
    d_3pa varchar(6),
	d_pts varchar(6),
    pace varchar(12),
	won	varchar(6),
    lost varchar(6),
	primary key(team, leag, year_date)
);


create table nba_calebwatson_chaseperry.teams(
	team varchar(5) not null,
    location varchar(15),
    name_ varchar(15),
    league varchar(6) not null,
    primary key(team, league)
);
    
    
create table nba_calebwatson_chaseperry.draft(
	draft_year year not null,
    draft_round varchar(5) not null,
    selection varchar(5) not null,
    team varchar(8) not null,
    firstname varchar(15) not null,
    lastname varchar(25) not null,
    ilkid varchar(20),
    draft_from varchar(35),
    leag char(5) not null,
    primary key(draft_year, draft_round, selection, team, firstname, lastname, leag)
);
        
