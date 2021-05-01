sing_a_song(ananya).
listens_to_music(rohit).


listens_to_music(ananya) :- sing_a_song(ananya).
happy(ananya) :- sing_a_song(ananya).
happy(rohit) :- listens_to_music(rohit).
plays_guitar(rohit) :- listens_to_music(rohit).
