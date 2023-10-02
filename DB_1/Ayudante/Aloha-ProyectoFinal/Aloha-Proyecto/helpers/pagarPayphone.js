import axios from "axios";

export default async function PagarPayphone(total, email, external_id) {
  try {
    const { data } = await axios.post(`http://localhost:4000/api/productos/pagar`, {
      amount: `${parseInt(total.toFixed(2) * 100)}`,
      amountWithoutTax: `${total.toFixed(2) * 100}`,
      clientTransactionId: external_id,
      email: email
    });
    window.location = data.payWithCard
  } catch (error) {
    console.log(error);
  }
}
