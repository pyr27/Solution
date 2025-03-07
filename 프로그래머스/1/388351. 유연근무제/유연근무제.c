#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 시각을 분 단위로 변환하는 함수
int time_to_minutes(int time) {
    return (time / 100) * 60 + (time % 100);
}

int solution(int schedules[], size_t schedules_len, int** timelogs, size_t timelogs_rows, size_t timelogs_cols, int startday) {
    int answer = 0;

    // 토요일, 일요일의 인덱스 계산
    int sat_idx = (6 - startday + 7) % 7;  // 토요일 인덱스
    int sun_idx = (7 - startday + 7) % 7;  // 일요일 인덱스

    for (size_t i = 0; i < timelogs_rows && i < schedules_len; i++) {  
        bool valid = true;
        
        // 희망 출근 시간(시분)을 분 단위로 변환
        int target_time = time_to_minutes(schedules[i]);
        
        for (size_t j = 0; j < 7; j++) {  
            if (j == sat_idx || j == sun_idx) continue;  // 주말 제외

            // 출근 시간을 분 단위로 변환
            int arrival_time = time_to_minutes(timelogs[i][j]);

            // 출근 시간이 기준 +10분을 초과하면 실패
            if (arrival_time > target_time + 10) {
                valid = false;
                break;
            }
        }

        if (valid) answer++;
    }

    return answer;
}
