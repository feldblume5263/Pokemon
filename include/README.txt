## 프로젝트 구성에서 모든 jsoncpp 관련 파일들은 제거
jsoncpp open source 라이브러리를 프로젝트에 인클루드 하는법

visual studio IDE 기준,
프로젝트 설정 - 
C/C++ 탭 -
일반 탭 - 
추가 포함 디렉터리 설정을 다음과 같이 바꿔준다:
	$(ProjectDir)\include\jsoncpp-1.8.4\include 

그 후 라이브러리를 링크하기 위해
프로젝트 설정 - 
링커 탭 - 
일반 탭 - 
추가 라이브러리 디렉터리 설정을 다음과 같이 바꿔준다:
	$(ProjectDir)\include\jsoncpp-1.8.4\makefiles\msvc2010\Debug

