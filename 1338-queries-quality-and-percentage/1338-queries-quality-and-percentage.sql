SELECT query_name, 
ROUND(SUM(rating / position) / COUNT(query_name), 2) as quality,
ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) * 100, 2) as poor_query_percentage
FROM queries
GROUP BY query_name