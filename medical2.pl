% introduction of interface and driver function
akshats_hospital :-
    write_ln('What is your name? '),
    read(Patient),
    write_ln('What is the problem? '),
    read(Problem),
    check_up_for(Patient,Problem),nl,
	write('You probably have '),write(Problem),
    recommendations(Problem).

% incase the program cannot figure out the disease from symptoms
akshats_hospital :-
    write(' Sorry the system cannot diagnose your disease').

% ask whether a patient has a particular symptom
symptom(Patient,short_breath) :- 
check(Patient," do you have a short breathness (y/n) ?").
symptom(Patient,fever) :- 
check(Patient," do you have a fever (y/n) ?").
symptom(Patient,rash) :- 
check(Patient," do you have a rash (y/n) ?").
symptom(Patient,headache) :- 
check(Patient," do you have a headache (y/n) ?").
symptom(Patient,runny_nose) :- 
check(Patient," do you have a runny_nose (y/n) ?").
symptom(Patient,conjunctivitis) :- 
check(Patient," do you have a conjunctivitis (y/n) ?").
symptom(Patient,cough) :- 
check(Patient," do you have a cough (y/n) ?").
symptom(Patient,body_ache) :- 
check(Patient," do you have a body_ache (y/n) ?").
symptom(Patient,chills) :- 
check(Patient," do you have a chills (y/n) ?").
symptom(Patient,sore_throat) :- 
check(Patient," do you have a sore_throat (y/n) ?").
symptom(Patient,sneezing) :- 
check(Patient," do you have a sneezing (y/n) ?").
symptom(Patient,swollen_glands) :- 
check(Patient," do you have a swollen_glands (y/n) ?").
symptom(Patient,dehydration) :- 
check(Patient," do you have a dehydration (y/n) ?").
symptom(Patient,abdominal_pain) :- 
check(Patient," do you have a abdominal_pain (y/n) ?").
symptom(Patient,nausea) :- 
check(Patient," do you have a nausea (y/n) ?").
symptom(Patient,bad_stool) :- 
check(Patient," do you have a stool problems (y/n) ?").

% logic to see whether the patient answered yes to particular symptom or not
ask_question(Patient,Question) :-
	write(Patient),write(Question),
	read(Reply),
	( (Reply == yes ; Reply == y)
      ->
       assert(yes(Question)) ;
       assert(no(Question)), fail).

:- dynamic yes/1,no/1.	

% provide recomendations in general
recommendations(diarrhea):- 
    write_ln('Drink 8-10 cups of fluid per day'),
    write_ln('Try sources of soluble fibre to help firm up stool.'),
    write_ln('Eat small frequent meals slowly during the day.').
 
recommendations(common_cold):- 
    write_ln('Try Steam inhalation'),
    write_ln('Eating warm soup'),
    write_ln('Drink plenty of fluids').

recommendations(pneumonia):- 
    write_ln('Eat healthy'),
    write_ln('Resting, avoid work'),
    write_ln('keep checking your temparature regularly').

recommendations(flu):- 
    write_ln('Decrease social contact as it maybe contagious'),
    write_ln('Avoid heavy food'),
    write_ln('Drink ample water').

recommendations(chicken_pox):- 
    write_ln('Try cold baths with baking soda'),
    write_ln('Drink lots of liquids such as water, juice and soup, especially if there is a fever.'),
    write_ln('Don''t be bedridden, keep regular movement').	

% decide wehrther the answer was true or false                                                       
check(Patient,Querry) :-
   (yes(Querry) -> true ;
    (no(Querry) -> fail ;
     ask_question(Patient,Querry))).
                                                         
% clean the database                                                      
undo :- retract(yes(_)),fail. 
undo :- retract(no(_)),fail.
undo.

% for a disease check wehter the patient has its symptoms or not                                                        
check_up_for(Patient,diarrhea) :-
  symptom(Patient,dehydration);
  symptom(Patient,fever),
  symptom(Patient,abdominal_pain),
  symptom(Patient,headache),
  symptom(Patient,nausea);
  symptom(Patient,bad_stool).

check_up_for(Patient,common_cold) :-
  symptom(Patient,sore_throat),
  symptom(Patient,runny_nose),
  symptom(Patient,chills),
  symptom(Patient,headache),
  symptom(Patient,sneezing).

check_up_for(Patient,pneumonia) :-
  symptom(Patient,fever),
  symptom(Patient,short_breath);
  symptom(Patient,headache),
  symptom(Patient,cough),
  symptom(Patient,nausea).

check_up_for(Patient,flu) :-
  symptom(Patient,fever),
  symptom(Patient,headache);
  symptom(Patient,body_ache),
  symptom(Patient,conjunctivitis);
  symptom(Patient,chills;
  symptom(Patient,sore_throat),
  symptom(Patient,runny_nose),
  symptom(Patient,cough).

check_up_for(Patient,chicken_pox) :-
  symptom(Patient,fever);
  symptom(Patient,chills),
  symptom(Patient,body_ache);
  symptom(Patient,rash).
