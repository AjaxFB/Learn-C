#Begin git directory
git init
#Add, move and remove files of git
echo "Hello" >> Hello.txt
mkdir directory
git add --cached <file or folder> #--cached delete only git, file system is intact
git rm --cached <file or folder> # \* select all files
git mv <file1> <file2>
##nano tip: Ctrl+k CUT Ctrl+u PASTE
#Configure remote to use
git remote add origin https://github.com/AjaxFB/Problemas.git
git remote -v #show names
git remote show <remoto> #show informations of specific remote
git remote rename <remoto1> <remoto2>
#Save changes
git commit -a -m <comentario> #-a add include
git commit --amend #overwrite the last commit
#Delete old commits
git reset --hard <sha1-commit-id>
git push origin HEAD --force
git reflog #remake log
#Check logs and commits
git log -p -2 --stat --pretty=format:"%h - %an, %ar : %s" #oneline #-p diff include #-2 2 last modifications
git log --pretty=format:"%h %s" --graph #show graph of commits
#Set branch master to origin remote
git push -u origin master
#Checkout
git checkout -- <file> #remove file of selection
#Clone
git clone git://github.com/<user>/<project>.git <folder_optional>
#Others
git status
cat .gitignore #(!obriga rastreio__/ignora somente arquivo e nao diretorio__somente diretorio/)
git diff --staged --cached
git help <command>
git fetch <project> #um git clone que atualiza
git pull #fetch with merge
git tag -a v1.4 -m 'my version 1.4' #also exists tags assinadas -s //git show v1.4
git branch <name>
git chekout <branch> #sai do branch atual e vai para o branch informado//-b muda e cria//-d deleta
git merge <branch> #uni branch atual com branch informado
#pegando email do commit de um projeto
OpçoesDescriço da sada
%HHash do commit
%hHash do commit abreviado
%Trvore hash
%trvore hash abreviada
%PHashes pais
%pHashes pais abreviados
%anNome do autor
%aeEmail do autor
%adData do autor (formato respeita a opço -date=)
%arData do autor, relativa
%cnNome do committer
%ceEmail do committer
%cdData do committer
%crData do committer, relativa
%sAssunto
