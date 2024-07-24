# yhan_ROS2

### 2024-07-23 - 1차시 가상환경설정 세팅

vmware17 설치
ubuntu 22.04 설치
> VMware 17 --> 22.04 ubuntu --> iso image 가상환경 생성

우분투에
> terminator 설치 <br>
> vscode 설치 <br>
> git 설치 ... github 연동

opencv 이론교육 
>  컴퓨터 비전 개요 <br>
>  저수준, 고수준 영상처리 <br>
>  영상 획득과정 : 빛 - 렌즈 - 이미지 센서 - ADC - ISP - 사진 파일 <br>
>  영상? : 위치, 밝기 값을 가진 일정한 수의 화소들의 모임 <br>
>  BMP, JPG, GIF, PNG

설치(리눅스)
데비안 설치(패키지 관리자'apt' 통해 OpenCV라이브러리와 그에 필요한 헤더파일 자동 설치 사용)
> sudo apt update <br>
> sudo apt install libopencv-dev python3-opencv
or 소스 코드 빌드 & 설치 (권장, but 시간 오래)

* makefile -> 자동으로 컴파일 명령어 넘김
cmake -> cmakelist.txt -> make  ||  CMakeLists 파일 제대로 작성하는 것 중요.


- - -
### 2024-07-24 - 2차시

1. matOp1 - mat 생성자예제
2. matOp2 - clone, copyTo | DeepCopy예제
3. matOp3 - roi, setTo
4. matOp4 - pixel change
5. matOp5 - outer memories
6. rectOp, vecOp - rect, vector, scalar, color
> *OpenCV -> BGR -> OpenCV 첫 개발당시 사용된 비디오 카메라 코덱이 BGR 형식 사용
7. video - videocapture
8. line - 선 그려보기
9. rectangleTest - 여러 도형 그려보기
10. drawText - 글씨 출

makefile? 소스 파일들을 쉽게 빌드하도록 돕는 make 프로그램의 설정파일 <br>
make? 컴파일 및 빌드과정 자동화 + incremental build지원 (수정된 파일만 다시 빌드) <br>
참고자료 : https://code-lab1.tistory.com/370 

CMake? 빌드 파일을 생성해주는 프로그램

- CMake 통해서 프로젝트 빌드 X
- CMake → 빌드파일 생성 → 빌드프로그램 통해 프로젝트 빌드
- 예) make를 사용한다면, CMake → Makefile → Make
- Ninja빌드?

참고링크 : https://cho001.tistory.com/229 
https://gist.github.com/luncliff/6e2d4eb7ca29a0afd5b592f72b80cb5c
