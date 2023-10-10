$(document).ready(function() {
    // alert("ready");
    console.log("Ready!");
    $(".boton").click(function() {
      let name = $("#name").val();
      let surname = $("#surname").val();
  
      // save to table
      let table = $(".myTable");
      let row = $("<tr>");
      let data = $("<td>");
  
      row.append($("<td>").text(name));
      row.append($("<td>").text(surname));
      table.append(row);
  
  
      // message
      alert("Data has been succesfully saved!")
      alert(`Welcome ${name} ${surname}`);
    })
  })
  