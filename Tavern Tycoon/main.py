#launch the ui and coordinate other modules(?)

from tkinter import *
import random


root = Tk()
root.title("Fantasy Tavern Manager")
root.geometry("640x480")

text1 = Label(root, text="Proto build")
text1.place(x=0,y=0)

rules = Label(root, text="Every tenth week, the royal tax collector will come and take the king's taxes; 1/10 of all the revenue you made in that time!", justify="left", wraplength=300)
rules.place(x=300,y=0)

global money
global food
global drink

global week
global revenue

money = 1000
food = 0
drink = 0

week = 0
revenue = 0

money_desc = Label(root, text="Funds:")
money_desc.place(x=0,y=30)

food_desc = Label(root, text="Food:")
food_desc.place(x=100,y=30)

drink_desc = Label(root, text="Ale:")
drink_desc.place(x=200,y=30)

money_text = Label(root, text="$ 1000", justify="left")
money_text.place(x=0,y=60)

food_text = Label(root,text="0",justify="left")
food_text.place(x=100,y=60)

drink_text = Label(root,text="0",justify="left")
drink_text.place(x=200,y=60)

end_week_report = Label(root, text="", wraplength=300, justify="left")
end_week_report.place(x=0,y=120)

def end_week():
    global money
    global food
    global drink
    global week
    global revenue


    #Put the guests and spending in a loop to individually calculate every day
    week_guests = 0
    week_rev = 0

    average_spending = 0

    for x in range(7):
        #create a random number of guests
        guests = random.randrange(0,30,1)

        day_average = 0
        rev = 0

        #create the average amount they spent
        for y in range(guests):

            #either buy food, drink, or both
            buying = random.randrange(0,2,1)

            amount_f = 0
            amount_d = 0

            if buying == 0 and food > 0:
                amount_f = random.randrange(0,5,1)
                rev += (2 * amount_f)
                day_average += (2 * amount_f)
                food -= amount_f
                if food < 0:
                    food = 0
            elif buying == 1 and drink > 0:
                amount_d = random.randrange(0,10,1)
                rev += (2 * amount_d)
                day_average += (2 * amount_d)
                drink -= amount_d
                if drink < 0:
                    drink = 0
            else:
                if food > 0 and drink > 0:
                    amount_f = random.randrange(0,5,1)
                    amount_d = random.randrange(0,10,1)
                    rev += (2 * amount_f) + (2 * amount_d)
                    day_average += (2 * amount_f) + (2 * amount_d)
                    food -= amount_f
                    drink -= amount_d
                    if food < 0:
                        food = 0
                    if drink < 0:
                        drink = 0
                elif food > 0 and drink <= 0:
                    amount_f = random.randrange(0,5,1)
                    rev += (2 * amount_f)
                    day_average += (2 * amount_f)
                    food -= amount_f
                    if food < 0:
                        food = 0
                elif food <= 0 and drink > 0:
                    amount_d = random.randrange(0,10,1)
                    rev += (2 * amount_d)
                    day_average += (2 * amount_d)
                    drink -= amount_d
                    if drink < 0:
                        drink = 0

        if guests > 0:
            day_average = day_average / guests
        average_spending += day_average

        week_guests += guests
        week_rev += rev

        money += rev



    #calculate average spending
    average_spending = average_spending / 7

    week += 1
    revenue += rev

    if week % 10 == 0:
        tax = revenue / 10
        money -= tax
        revenue = 0
        report = "Last week, " + str(week_guests) + " guests visited your tavern. On average, they spent ${:.2f}. This resulted in an income of $" + str(week_rev) + " for the tavern. The King's Tax collector visited last week, righteously taking $" + str(tax) + " as taxes for the King!"
    else:
        report = "Last week, " + str(week_guests) + " guests visited your tavern. On average, they spent ${:.2f}. This resulted in an income of $" + str(week_rev) + " for the tavern."

    

    temp = "$ " + str(money)
    money_text.config(text=temp)
    food_text.config(text=str(food))
    drink_text.config(text=str(drink))
        

    formatted_report = report.format(average_spending)

    end_week_report.config(text=formatted_report)

def increase_food():
    global money
    global food

    money -= 100
    food += 100

    tm = "$ " + str(money)
    money_text.config(text=tm)
    food_text.config(text=str(food))

def increase_drink():
    global money
    global drink

    money -= 100
    drink += 100

    tm = "$ " + str(money)
    money_text.config(text=tm)
    drink_text.config(text=str(drink))




end_week = Button(root, text="End Week", command=end_week)
end_week.place(x=0,y=90)

buy_food = Button(root, text="Buy Food", command=increase_food)
buy_food.place(x=100,y=90)

buy_drink = Button(root, text="Buy Ale", command=increase_drink)
buy_drink.place(x=200,y=90)



root.mainloop()