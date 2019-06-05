#This is the testing SQL queries for the DB Extra Credit assignment completed by Caleb Watson and Chase Perry.

select firstname, lastname from nba_calebwatson_chaseperry.players
where height_feet = (select max(height_feet) from nba_calebwatson_chaseperry.players)
and height_inches = (select max(height_inches) from nba_calebwatson_chaseperry.players
					 where height_feet = (select max(height_feet) from nba_calebwatson_chaseperry.players));
                     
select firstname, lastname from nba_calebwatson_chaseperry.coaches_career
where season_win = (select max(season_win) from nba_calebwatson_chaseperry.coaches_career);

select name_ from nba_calebwatson_chaseperry.teams
where location = 'San Diego';