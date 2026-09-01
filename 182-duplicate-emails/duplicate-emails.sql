# Write your MySQL query statement below
SELECT DISTINCT p.email AS Email
FROM person p
JOIN person e
    ON e.email = p.email
    WHERE e.id != p.id;