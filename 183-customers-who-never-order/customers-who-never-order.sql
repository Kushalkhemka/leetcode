# Write your MySQL query statement below
SELECT e.name AS Customers
FROM customers e
LEFT JOIN orders o
ON e.id = o.customerId
WHERE o.customerId IS NULL;