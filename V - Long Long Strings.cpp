// https://codeforces.com/gym/101652
/*
messi siemppre esta arriba
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠉⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣀⡠⠖⠒⠓⣦⢀⡞⠀⢰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣴⣪⠟⢙⣶⣴⣿⣿⣿⠟⠀⢲⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢻⣏⣠⣿⣿⣿⢿⣿⠋⠀⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠋⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢹⣹⣿⣿⡷⢖⢿⠭⠄⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣄⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⡞⠀⣏⡏⢀⣈⣄⢀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣾⣶⣾⣿⣯⣷⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣠⠌⠓⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢧⠀⡉⣄⣠⣝⠙⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡢⣄⠀⠀⠀⠀⠀⢀⣼⢁⣠⡾⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢸⠻⣖⢨⣻⡿⢱⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠉⠀⠀⠀⠉⠙⠿⣿⣿⣿⣿⣞⣦⡀⠀⠀⢠⠞⣶⡾⣿⣅⣴⠇⢈⡱⡄⠀⠀⠀⠀⠀⠀⠀
⠀⢸⣶⠸⣆⣯⣥⣼⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣥⠀⢀⣀⡀⠀⠀⠀⠀⡨⢻⣿⣿⣿⣿⣷⡀⠀⢻⣴⣿⣴⣿⣿⣿⣶⣿⣷⣾⡀⠀⠀⠀⠀⠀⠀
⠀⡼⣹⣴⣿⡦⣟⣹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⠿⠛⣤⣴⣿⣿⡷⣄⠀⠀⣴⣿⣿⣿⣿⣿⣿⣷⠀⠘⣆⣹⡋⠛⢹⣿⡷⠏⠀⢸⠁⠀⠀⠀⠀⠀⠀
⠀⡇⣿⢹⡌⣧⣽⢺⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣞⣁⠀⠀⠙⢿⠛⠿⠟⠈⠰⠀⢹⣿⣿⣿⣿⣿⣿⣿⡇⠀⢹⡋⢀⢰⡟⠁⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀
⠀⣟⣿⠟⠛⣯⡀⡌⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣨⣿⣿⣶⠄⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠳⣿⣾⣅⣀⣀⠀⠸⡇⠀⠀⠀⠀⠀⠀⠀
⠀⣏⣼⣦⣔⣚⣹⣇⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢿⣿⣽⣿⣦⡀⠀⠀⠀⠀⠀⣀⣤⡘⣛⢩⣯⣿⣿⣿⠏⠀⠀⠀⠀⠙⣷⠿⡉⠿⠿⠀⠹⡄⠀⠀⠀⠀⠀⠀
⠀⣿⡀⢻⣿⣿⡋⢸⡌⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡌⣾⣭⠉⢻⡷⠀⢠⡄⠀⠨⣿⣿⣤⣿⡟⠆⣏⣿⠋⠀⠀⠢⠀⠀⠀⠈⢣⠙⠳⠄⠀⠀⢳⠀⠀⠀⠀⠀⠀
⠀⣧⣷⣿⣿⣿⣿⣿⣟⣈⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⣳⡏⣁⣐⣿⣿⣆⣨⣿⣹⣶⣫⣿⣝⣗⣲⣾⠟⠁⠀⠀⠀⠨⠀⠀⠀⠀⠀⢧⠀⠀⠀⠀⠈⢧⠀⠀⠀⠀⠀
⠀⢹⠉⣽⣯⣄⣀⣽⢻⣿⠞⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠋⢱⣿⠋⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠸⡌⠄⠀⠀⠀⠈⢧⠀⠀⠀⠀
⠀⠈⣿⣿⣿⣫⣿⣽⡿⠛⣶⢿⡟⠓⠢⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⣀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⢸⠃⠀⠀⠀⠀⠀⠁⠀⡀⠀⠀⠀⠀⠀⢧⠀⠀⠀⣀⠀⠈⢣⡀⠀⠀
⠀⠀⢸⡿⣿⣷⣽⣿⣿⣶⠾⠦⠆⠀⠀⠂⠀⠈⠉⠉⠓⠒⠺⠉⠉⠉⠉⠉⠉⠀⠀⡌⢳⣀⡀⠀⣷⢿⣿⡿⣿⠻⠟⠛⠈⢤⠈⠀⣻⢤⣀⡀⠀⣀⣀⣀⠀⠂⠀⠀⠀⠀⠀⢸⠀⠁⢀⠀⠀⠀⠀⢣⠀⠀
⠀⠀⠸⣿⣿⣿⣿⣿⣿⡏⠁⠀⡇⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠹⡄⡀⠨⣽⡋⠁⢬⡿⠆⠁⠀⠀⠀⣁⠴⠊⠁⠀⢀⡊⠉⠁⠀⠈⠙⡟⠓⠒⠢⣤⣀⡈⡆⠀⠀⠀⣦⠀⠀⠈⢧⠀
⠀⠀⠀⠈⠻⢿⣿⣿⣿⣷⡄⠰⣷⠀⢀⣁⣀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⣠⢶⣄⠀⠀⢱⡙⣄⠈⠧⠤⣀⣤⠤⠤⠖⠚⠉⠀⠀⢀⠴⠚⢿⡇⠀⠀⠀⠀⢀⠅⢀⣴⣶⣿⣿⠿⠿⡆⢀⡘⠹⣆⠀⠀⠈⣆
⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⣿⣆⣌⣇⠀⢿⠠⢭⡙⠒⠒⠤⠄⠀⡀⢀⡼⠁⠈⢙⣆⠀⠀⠉⠁⠀⠀⠀⢀⣀⣀⡄⠀⠀⠀⢠⡶⠉⠀⣰⢺⠃⠀⠀⠀⠠⠁⢠⣾⣿⣿⡿⠁⠀⠀⢳⡏⠀⣠⣿⡄⠀⠀⢸
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⡆⠈⢷⣄⠓⣦⠀⡀⢰⢲⠇⢸⠉⢳⡴⠋⠈⢧⠀⠀⠀⠀⣀⠈⢿⣃⢰⠃⢀⡤⠤⠽⢒⡞⠉⠁⢹⠀⠀⢸⠺⡤⢰⣿⣿⣿⣿⡇⠀⠀⠀⠘⣷⡾⠿⣿⣷⡄⠀⢸
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢯⡉⣀⣨⣿⣷⣬⣦⠸⡜⣿⠀⠘⢳⡾⠿⣿⣿⡏⠀⠀⠀⡞⢠⠞⠛⠛⠋⠀⣼⣿⣷⣷⢸⣽⠀⠀⢸⠀⠀⠈⣷⢷⣸⣿⣿⣿⣿⣿⣀⡀⠀⠀⠙⠦⠤⣠⣤⣷⣤⡞
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠙⠿⣝⢶⣧⡇⢀⠇⢰⠋⣳⡀⠉⠀⠀⣴⠿⡵⣄⣀⠀⠀⠀⠀⢷⣿⠿⠿⢓⣾⣤⣶⣾⠄⠀⠀⣻⢸⣿⣹⣿⣿⣿⣿⣷⣤⣴⣶⣾⣿⣿⣿⠟⠋⠁⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣌⠀⢸⠒⠋⠘⢩⠃⠀⠀⣠⣿⠶⢣⣶⣶⣦⣄⠀⠀⠘⢛⣿⡿⠿⡷⠟⠋⡝⠀⠀⠀⡿⣼⣿⡿⣿⡏⢻⣿⣿⣿⡿⠿⠿⠛⠉⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⢸⠀⠀⠀⠈⠀⠀⠀⢉⣿⢀⣿⡏⠹⠿⣿⠄⠀⠀⠀⠙⠚⣰⠀⠁⠈⡇⠀⠀⢰⡇⣿⣟⢠⣯⡀⣿⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢸⠀⠀⠀⠀⠀⠀⠀⣸⡿⢸⣿⠀⠀⢸⣿⠀⠀⠀⢀⠇⠀⡏⠁⠀⢸⠁⠀⠁⢸⡇⢿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢸⠀⠀⡀⠀⠀⠀⢀⣿⠇⣿⡇⠀⠀⣿⡇⠀⠀⠀⣸⠀⠀⢱⣀⠀⣸⠀⠀⠀⢸⠇⣳⢟⣭⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⡇⠀⠀⠀⣸⡿⠠⣿⣷⣤⣾⡿⠀⠀⠀⠀⣿⢧⡀⠀⠀⠳⡇⠀⠠⠀⢸⣀⡟⢣⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢸⠃⠀⠀⠀⢸⣇⠀⠈⣙⡟⠁⠀⠀⠀⠀⠀⠻⠦⠭⠷⠆⣼⠁⠀⠀⠀⢸⢹⡇⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⣸⠙⢢⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠰⠀⠀⠀⢹⠀⠀⠀⠀⢸⣿⢳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠚⠃⠀⠀⠀⠀⠀⠀⠀⣠⣥⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⡇⠈⠳⢤⡀⠀⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀⠀⠀⢠⡄⠀⠀⠀⣹⠀⠀⠀⠀⠀⠀⠀⢧⣂⡢⠄⢹⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀⠀⠀⠀⢰⠊⢉⡇⠀⠀⠀⠀⠀⠀⠀⠀⠠⠼⢤⣯⠀⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠓⠄⠀⠀⠀⠀⢀⠄⠀⠈⠧⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⡃⠀⣠⡾⠀⠀⠀⠀⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⢸⣄⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⣴⠏⡇⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠲⠀⠀⠀⠀⠀⠈⠛⠳⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠍⠁⠀⠒⡇⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠛⠑⠀⠀⠀⢸⠇⠀⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
gracias por el perrito cheems
EL PEMRRITO MALVADO

⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣏⡽⠷⠾⠭⠍⠉⣯⣿⣶⢶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠞⣿⣦⣴⣤⣀⠀⠉⣛⠹⣮⡇⣿⣿⢶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠃⣴⣿⡯⠟⠀⠈⢀⠀⠹⡄⠙⣷⣿⣿⠶⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣴⣿⡟⠀⣰⣬⣿⣾⠗⠀⠀⠐⢯⠛⣧⠀⢘⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⡴⠀⠙⠉⠉⠈⠀⠀⠀⠀⠀⠀⣼⣶⠾⢾⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠻⠁⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⣠⣿⠙⣄⠾⠿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⣿⣿⣿⡿⠥⠀⠀⢀⣴⠀⠀⠀⠀⠀⣨⠀⠴⠋⠀⠘⠁⠀⣠⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠿⣿⣧⣤⣯⣿⡿⠋⠀⠀⠀⣤⠞⠀⠀⠀⠀⠀⠀⠀⠀⠟⠁⠘⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⠛⠁⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⢀⣴⠀⠀⠀⠀⠀⠀⠀⢳⣄⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠹⡦⠀⣀⣴⠏⠀⠀⠀⠀⠀⠀⠀⣀⣿⠙⢦⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣄⠀⠀⠀⠀⠀⠀⠀⠳⠖⠉⠀⠀⠀⠀⠀⠀⠁⠀⣴⠟⠩⠀⢠⣿⢦⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠀⠿⠀⠁⠀⠀⢀⣸⡯⠙⢷⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠤⠐⠈⠀⠀⠀⠀⠀⠀⠀⣠⠟⠃⠀⢸⣇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⢖⠀⠀⠀⠀⠀⠀⠀⠐⠚⠉⠀⠀⠀⠀⡴⡋⠀⠀⠀⠀⣦⡏⠀⠀⠀⣾⣿⡄⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢪⡞⠁⠀⠀⠀⠀⠁⠀⠀⠀⣶⠏⣿⣿⡄⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡦⡌⠳⠤⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠋⠀⣻⣹⣿⡄
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠋⠀⠀⠀⠀⠀⠀⢀⣾⠀⠀⠀⠀⣾⠀⠹⢿⣿⣷
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⣶⠀⠀⠀⠀⠀⣆⠀⠟⠀⠀⠀⠀⠀⡾⠃⠀⢠⡠⠀⢠⣾⣾⣿⣿⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⡿⠀⠀⠀⣰⣿⣀⠀⠀⠀⠀⢹⡤⡄⠀⠀⠀⠀⣸⣿⡀⣶⣶⣷⣶⣿⣿⣿⣿⡟⠁
⠀⠀⠀⠀⠀⠀⣀⡠⠶⠋⣸⣗⠀⠀⢀⣿⣻⣿⡦⠤⠤⠤⠿⣷⠇⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀
⠀⣀⡴⠖⠋⠉⠉⢀⣀⡴⣿⡏⠀⢀⣸⡟⠛⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀
⠘⢿⣷⣤⡤⠶⠚⠋⠁⢀⡟⠀⠀⣾⣿⣁⣀⠀⠀⠀⠀⠀⠀⣿⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⠿⠛⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣀⠴⢞⡿⠀⠀⢴⡿⠋⠉⠉⠉⠛⠲⠶⠤⣤⣿⠀⠀⢰⣿⣿⣿⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢀⣠⣶⡊⠉⢀⣠⠞⠁⠀⢀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⢸⣯⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠈⠉⠻⠶⣶⡟⠃⡴⠀⢀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠏⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠠⣿⣄⣾⣄⡷⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠁⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⡁⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣏⡇⠀⡶⠀⣸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠹⣇⣴⠷⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vii build()
{
    vector<pair<int, ii>> sat;
    vii chil(10000);
    vi par(10000);
    sat.pb({1e11, {0, 0}});
    string s;
    int x = 1;
    while(true)
    {
        cout<<'\n';
        // for(auto cat : sat)
        //     cout<<cat.f<<' '<<cat.s.f<<' '<<cat.s.s<<'\n';
        // cout<<"#######\n";
        vector<pair<int, ii>> neo;
        cin>>s;
        // cout<<s<<'\n';
        if(s == "E") break;
        if(s == "D")
        {
            int pos;
            cin>>pos;
            int con = 0;
            fore(i, 0, sat.size())
            {
                int la = con;
                con += sat[i].f;
                if(con >= pos)
                {
                    int dif = con - pos;
                    if(sat[i].s.f == 0)
                    {
                        if(pos - la > 1)
                            neo.pb({pos - la - 1, {0, x++}});
                        if(pos < con)
                            neo.pb({con - pos, {0, x++}});
                    }
                    else if(!neo.empty() && neo.back().s.s == chil[sat[i].s.s].f && sat[i + 1].s.s == chil[sat[i].s.s].s)
                    {
                        int n = sz(neo) - 1;
                        neo[n].f += sat[i + 1].f;
                        neo[n].s.s = par[sat[i].s.s];
                        i++;
                    }
                    fore(j, i + 1, sat.size())
                        neo.pb(sat[j]);
                    break;
                }
                neo.pb(sat[i]);
            }
        }
        else
        {
            int pos;
            cin>>pos;
            char ch;
            cin>>ch;
            int con = 0;
            fore(i, 0, sat.size())
            {
                int la = con;
                con += sat[i].f;
                if(con >= pos)
                {
                    int dif = con - pos;
                    if(sat[i].s.f == 0)
                    {
                        bool ba = true;
                        if(pos - la > 1)
                        {
                            neo.pb({pos - la - 1, {0, x++}});
                            par[x] = sat[i].s.s;
                            chil[x].f = x - 1;
                        }
                        else if(i > 0 && sat[i - 1].s.f != 0)
                            par[x] = par[sat[i - 1].s.s], chil[x] = chil[sat[i - 1].s.s];
                        neo.pb({1, {ch, x++}});
                        chil[x - 1].s = x;
                        neo.pb({con - pos + 1, {0, x++}});
                    }
                    else
                    {
                        par[x] = par[sat[i].s.s];
                        chil[x] = chil[sat[i].s.s];
                        neo.pb({1, {ch, x++}});
                        neo.pb(sat[i]);
                    }
                    fore(j, i + 1, sat.size())
                        neo.pb(sat[j]);
                    break;
                }
                neo.pb(sat[i]);
            }
        }
        swap(sat, neo);
    }
        // cout<<'\n';
        // for(auto cat : sat)
        //     cout<<cat.f<<' '<<cat.s.f<<' '<<cat.s.s<<'\n';
        // cout<<"#######\n";
    vii raza;
    for(auto cat : sat)
        raza.pb({cat.f, cat.s.f});
    return raza;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	vii sat = build(), sot = build();
    if(sat == sot)
        cout<<0<<'\n';
    else
        cout<<1<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better