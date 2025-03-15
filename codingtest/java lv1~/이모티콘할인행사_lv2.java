class Solution {
    static final int[] dis = {10,20,30,40}; 

    static final int size = dis.length;

    static int maxUser = 0;

    static int maxAcc = 0;

    public int[] solution(int[][] users, int[] emoticons) {

        maxUser = 0;
        maxAcc = 0;
        perm(new int[emoticons.length], 0, emoticons.length, users, emoticons);

        return new int[] {maxUser,maxAcc};
    }



    public void perm(int[] selectedEmoDis, int n, int selectedEmoDisSize, int[][] users, int[] emoticons) {
        if(n == selectedEmoDisSize) {
            //계산
            int totalUser = 0;
            int totalAcc = 0;

            for(int[] user : users) {
                int userD = user[0];
                int userLim = user[1];

                int a = 0;
                for(int j=0; j<emoticons.length; j++) {
                    int selectedEmoDiscount = selectedEmoDis[j];
                    if(selectedEmoDiscount >= userD) {
                        a+=(emoticons[j] * (1- selectedEmoDiscount/100.0));
                    }
                }
                if(a >= userLim) {
                    totalUser++;
                }else {
                    totalAcc += a;
                }
            }

            if(totalUser > maxUser) {
                maxUser = totalUser;
                maxAcc = totalAcc;
            }else if(totalUser == maxUser && totalAcc > maxAcc) {
                maxAcc = totalAcc;
            }
            return;
        }
        for(int i=0; i<size; i++) {
            selectedEmoDis[n] = dis[i];
            perm(selectedEmoDis,n+1, selectedEmoDisSize, users, emoticons);
        }

    }
}