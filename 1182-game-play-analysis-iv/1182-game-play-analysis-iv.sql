/* Write your PL/SQL query statement below */
select round(count(B.player_id) / count(A.player_id), 2) as fraction 
from activity A
left join activity B
on A.player_id = B.player_id and A.event_date = B.event_date - 1
where (A.player_id, A.event_date) in (select player_id, min(event_date) from activity group by player_id);

/* we use left join because we need the total count of the first day players  */