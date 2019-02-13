build:
	g++ frati.cpp -o frati -Wall
	g++ planificare.cpp -o planificare -Wall
	g++ numaratoare.cpp -o numaratoare -Wall

run-p1:
	./frati

run-p3:
	./planificare

run-p4:
	./numaratoare

clean:
	rm -rf frati planificare numaratoare
