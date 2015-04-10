# Import modules for CGI handling 
import cgi, cgitb

# Create instance of FieldStorage 
data = cgi.FieldStorage()

# Get data from fields
x = data.getvalue("x")
y = data.getvalue("y")
playerID = data.getvalue("id")

#tu powinno byc przeslanie wspolrzednych i id wysylajacego do modelu
print
