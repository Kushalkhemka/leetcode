# Write your MySQL query statement below
-- Select A.player_id, A.event_date as first_login from Activity A, Activity B
-- where A.player_id=B.player_id AND DATEDIFF(A.event_date,B.event_date)<0;

Select player_id, MIN(event_date) as first_login from Activity
group by player_id;