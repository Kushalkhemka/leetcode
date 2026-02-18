# Write your MySQL query statement below
SELECT b.id from Weather a, Weather b
where DATEDIFF(b.recordDate, a.recordDate)=1 AND a.temperature<b.temperature;