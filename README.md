# yhan_ROS2

### 2024-07-23 - 1일차 가상환경설정 세팅

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
<br>
<br>
- - -
### 2024-07-24 - 2일차

1. matOp1 - mat 생성자예제
2. matOp2 - clone, copyTo | DeepCopy예제
3. matOp3 - roi, setTo
4. matOp4 - pixel change
5. matOp5 - outer memories
6. rectOp, vecOp - rect, vector, scalar, color
> *OpenCV -> BGR -> OpenCV 첫 개발당시 사용된 비디오 카메라 코덱이 BGR 형식 사용
7. video - 카메라 입력처리, 동영상 파일처리, 저장
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
<br>
<br>
- - -
### 2024-07-25 - 3일차

1. mouseTest - 이미지에 마우스로 선 그리기
2. mousetRGBPoint - 마우스 클릭시 BGR 값 저장
3. trackBarTest - 트랙바 값 조절에 따른 이미지에 선 그리기, 명암 조절
4. fileStorageRead - JSON 파일 데이터 읽어와 화면에 표시
5. brightness - 밝기조절
6. ch06Logical - 비트연산 해보기
7. histogram - 이미지 히스토그램 계산 후 그래프출
* 히스토그램은 이미지 처리에서 픽셀 값의 분포를 나타내는 그래프입니다. 히스토그램은 각 픽셀 값의 빈도수를 계산하여 해당 픽셀 값이 이미지에서 얼마나 자주 나타나는지를 보여줍니다.
* X축 (가로축): 픽셀 값 (0부터 255까지의 그레이스케일 값)을 나타냅니다. 0은 완전한 검정색을, 255는 완전한 흰색을 의미합니다.
* Y축 (세로축): 해당 픽셀 값의 빈도수 (출현 빈도)를 나타냅니다. 히스토그램의 Y축 값은 이미지 내에서 특정 픽셀 값이 몇 번 나타나는지를 나타냅니다.
> 히스토그램의 활용 <br>
> 히스토그램은 이미지의 명암 분포를 분석하는 데 유용합니다. 이를 통해 이미지가 어두운지, 밝은지, 또는 명암 대비가 높은지를 파악할 수 있습니다. 히스토그램 평활화, 명암 조절 등의 이미지 처리 기술은 히토토그램을 기반으로 수행됩니다. 만약 히스토그램의 특정 구간에 높은 값이 몰려 있다면, 해당 구간의 픽셀 값이 이미지에 많이 포함되어 있다는 것을 의미합니다. 예를 들어, 0-50 구간에 높은 값이 있다면, 이미지가 전반적으로 어둡다는 것을 알 수 있습니다. 반대로 200-255 구간에 높은 값이 있다면, 이미지가 밝다는 것을 알 수 있습니다.
<br>
8. histogramEqualization - 명암 조절 후 반환
9. bilateralFilter - 가우시안 노이즈 추가 -> 다양한 필터로 노이즈 제거 부드럽게 처리.
10. blurr - 이미지 블러 처리
11. filter2D - 엠보스 필터 적용 이미지를 입체적으로
12. gaussianFilter - 가우시안 블러 sigma 값 수정 
13. shapen - 이미지 선명도 처리
<br>
<br>
- - - 
### 2024-07-26 4일차

1. affine - Affine 변환 , 이미지 크기 기울기 이동. 조정가능한 선형변환방법.
2. affineRotation - 트랙바 이용하여 이미지 실시간으로 회전시키기.
3. perspectiveCard - 원근변환(펙티브변환) 4개 점 선택하여 원근변환 적용 후 변환된 이미지 출력
4. perspectiveTransform - 원근변환
5. canny - 엣지 검출에 사용되는 케니함수 예제
6. houghline - canny 엣지 감지와 hough 변환으로 이미지에서 선 검출.
7. ch10color - 이미지 각 채널별로 분리 RGB
8. ch10_splitmerge - 이미지 픽셀 수정 및 표시.
