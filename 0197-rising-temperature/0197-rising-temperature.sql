select b.id
from Weather a
join Weather b
on b.recordDate = date_add(a.recordDate , interval 1 day)
where a.temperature < b.temperature;
