export default async function timeout() {
  return new Promise(r => setTimeout(r, 2000));
}