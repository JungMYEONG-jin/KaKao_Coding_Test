-- 코드를 입력하세요
SELECT 
ugb.BOARD_ID, ugb.WRITER_ID, ugb.TITLE, ugb.PRICE, 
case when ugb.STATUS = 'SALE' then '판매중'
     when ugb.STATUS = 'RESERVED' then '예약중'
     ELSE '거래완료' 
end as STATUS
from USED_GOODS_BOARD as ugb
where ugb.CREATED_DATE between '2022-10-05 00:00:00' and '2022-10-05 23:59:59'
order by ugb.BOARD_ID DESC
