function stopRefresh(event) {
    event.preventDefault(); // Stops page from refreshing
}
class BankAccount {
    BankAccount(name ,age , adharno , pan , adress , pin , email , phno ,accnum , ifsc , securitypin) {
    this.name = name
       this.age = age;
       this.adharno = adharno;
       this.pan = pan;
       this.adress = adress;
       this.pin = pin;
       this.email = email;
       this.phno = phno;
       this.accno = accnum;
       this.ifsc = ifsc;
       this.securitypin = securitypin;
       this.bal;
    }
    deposite(amount) {
       if(amount >= 0) {
         this.bal = this.bal + amount;
         console.log("new bal:- " + this.bal); 
       } else {
        alert("Invalid amount");
       }
    }
    withdraw(amount,secpin){
        if (secpin == this.securitypin) {
        if (amount > 0 && this.bal >= amount) {
           this.bal = this.bal - amount;
           console("new bal"+this.bal);
        } else {
            alert("Something went wrong or Insufficient balance");
        }
    } else{
        alert("invalid Pin");
    }
}
    serachAccount(accno){
      if (accno == this.accno) {
        console.log(this.name);
        console.log(this.age);
        console.log(this.adharno);
        console.log(this.pan);
        console.log(this.adress);
        console.log(this.pin);
        console.log(this.email);
        console.log(this.phno);
        console.log(this.bal);
      }
    }
};

let btn = document.querySelector("#submitbtn");
btn.addEventListener("click" , ()=>{
    let name = btn.form[0].value;
    let age = btn.form[1].value;
    let adharno = btn.form[2].value;
    let pan = btn.form[3].value;
    let adrees = btn.form[4].value;
    let pin = btn.form[5].value;
    let email = btn.form[6].value;
    let phno  = btn.form[7].value;

    let accno = phno.slice(0,5);
    let ifsc = "SBIN0008140"
    let securityPIN = Math.floor(Math.random() * 1000);

    let username = name + accno;
    let i = 0;
    for(i; i < 1000;i++) {
    let i = new BankAccount(name,age , adharno, pan,adrees,pin,email,phno,accno,ifsc,securityPIN);
    i++;
    }
    document.querySelector("#accheading").innerHTML = name + "your Account Details are :-"
    document.querySelector("#accno").innerHTML = "Account Number :- " + accno;
    document.querySelector("#ifsc").innerHTML = "IFSC :- " + ifsc;
    document.querySelector("#securitypin").innerHTML ="Security PIN :- " +  securityPIN;

    

    
});

let depBtn = document.querySelector("#deposite-submitbtn");
depBtn.addEventListener("click" , ()=>{
     let name = depBtn.form[0].value;
     let accno = depBtn.form[1].value;
     let amount = depBtn.form[2].value;
     let accountholder = ()=>{
          for (let i = 0; i < 1000;i++) {
            if(i.name == name && i.accno == accno) {
                return i;
            }
          }
          alert("Account not Found create a new Account");
     }; 
     console.log(i.name, i.accno);
     i.deposite(amount);
     
});