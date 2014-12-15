#Classic JavaScript Pitfalls
Certainly I feel that I have been spoiled by JavaScipt these days; I mean, it's just... ubiquitous. I kinda miss the old days when I thought that it's a sucky language and would not never have to touch the deep inside of it. However to my understanding the current trend is:
- frontend --- JavaScript (AngularJS, BackboneJS, EmberJS...)
- backend --- JavaScript (NodeJS)
- Hybrid Mobile Appication --- JavaScript (Cordova, Ionic, PhoneGap...)
- Testing Automation --- JavaScript (PhantomJS, Selenium, CapserJS...)
- Cross Platform Desktop Application: Oh yeah, finally, let us show off some C#.NET, Cocoa Desktop, QT skills, but the answer is... maybe JavaScript...? (Node Webkit)

Gosh Darn it! Give me a break.

I miss you all, buddies; and I truly like your syntax candies: Ruby, Python, even those C-family members... But sorry, not you, my dear PHP.

It's a good time to cite down some common and classic pitfalls what I encountered over my JavaScript journey.

### #1: All about the scope
```javascript
    var arr = 10;
    it();

    function it() {
      var arr = 21;
      alt();
      console.log(arr);
    }

    function alt() {
      arr = arr*5;
      console.log(arr);
    }

    output: 50, 21
```

### #2: Hoist the local variable in function and block scope.
```javascript
    var a = 1;
    function it() {
      console.log(a)
      var a = 2;
      console.log(a)
    }
    it();

    output: undefined, 2

```

### #3 Object-Oriented JavaScript

** function expression **
```javascript
    function Person(name, age, job){
        this.name = name;
        this.age = age;
        this.job = job;
        this.detail = function(){
            console.log("Name: " + this.name);
            console.log("Age: " + this.age);
            console.log("Job: " + this.job);
            console.log(this);// Person { name=" ", age=.., etc...}
        }
    }
    var person = new Person("C.T Xue", 22, 'Software Developer');
    person.detail();

```
