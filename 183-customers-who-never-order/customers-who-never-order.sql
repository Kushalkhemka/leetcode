# Write your MySQL query statement below
SELECT e.name AS Customers
FROM Customers e
WHERE e.id NOT IN (SELECT customerId FROM Orders);