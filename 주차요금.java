int[] answer = {};
        int base_time = fees[0];
        int base_cost = fees[1];
        int div_time = fees[2];
        int div_cost = fees[3];

        int last_hour = 23;
        int last_minute = 59;

        Map<String, String> inDB = new HashMap<>();// 어차피 한번 들어오고 나가야됨
        Map<String, Integer> timeDB = new HashMap<>();
        for(String record : records)
        {

            String[] info = record.split(" ");
            //0 time 1 car_number 2 in or out
            if(info[2].equals("IN"))
                inDB.put(info[1], info[0]); // car_number time
            else if (info[2].equals("OUT"))
            {
                if(inDB.containsKey(info[1]))
                {
                    String inTime = inDB.get(info[1]);
                    String outTime = info[0];
                    inDB.remove(info[1]); // 해당차량 제거

                    String[] in = inTime.split(":");
                    String[] out = outTime.split(":");
                    int inHour = Integer.parseInt(in[0]);
                    int outHour = Integer.parseInt(out[0]);
                    int inMinute = Integer.parseInt(in[1]);
                    int outMinute = Integer.parseInt(out[1]);

                    int total_Time = (outHour*60+outMinute)-(inHour*60+inMinute);
                    if(timeDB.containsKey(info[1]))
                        timeDB.put(info[1], timeDB.get(info[1])+total_Time);
                    else
                        timeDB.put(info[1], total_Time);
                }
            }
        }//위키랑 깃 계정 셋팅

        if(!inDB.isEmpty())
        {
            for(String number : inDB.keySet())
            {
                String time = inDB.get(number);
                String[] in = time.split(":");
                int inHour = Integer.parseInt(in[0]);
                int inMinute = Integer.parseInt(in[1]);
                int total_Time = (last_hour*60+last_minute)-(inHour*60+inMinute);
                if(timeDB.containsKey(number))
                    timeDB.put(number, timeDB.get(number)+total_Time);
                else
                    timeDB.put(number, total_Time);
            }
        }
        Map<Integer, Integer> result = new HashMap<>();
        Set<String> keys = new HashSet<>();
        keys = timeDB.keySet();
        for(String number : keys)
        {
            int times = timeDB.get(number);

            if(times<=base_time)
            {
                result.put(Integer.parseInt(number), base_cost);

            }else
            {
                int cost = base_cost + (int)Math.ceil((times - base_time)/(div_time+0.0)) * div_cost;
                result.put(Integer.parseInt(number), cost);

            }
        }

        List<Integer> list = new ArrayList<>(result.keySet());
        int[] nums = list.stream().mapToInt(i->i).toArray();
        Arrays.sort(nums);
        answer = new int[result.size()];

        for(int i=0;i<nums.length;i++)
            answer[i] = result.get(nums[i]);

        return answer;
