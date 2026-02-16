# Write your MySQL query statement below
Select score, 
Dense_Rank() OVER (order by score desc) as "rank" from scores;