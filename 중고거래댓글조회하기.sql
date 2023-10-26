-- 코드를 입력하세요
SELECT 
ugb.TITLE, ugb.BOARD_ID, ugr.REPLY_ID, ugr.WRITER_ID, ugr.CONTENTS, DATE_FORMAT(ugr.CREATED_DATE, '%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD as ugb
left outer join USED_GOODS_REPLY as ugr
on ugb.BOARD_ID = ugr.BOARD_ID
where ugb.CREATED_DATE BETWEEN '2022-10-01 00:00:00' and '2022-10-31 23:59:59' and ugr.REPLY_ID is not null
order by ugr.CREATED_DATE, ugb.TITLE 
